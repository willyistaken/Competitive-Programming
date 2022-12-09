#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct DSU{
	vector<pair<int,int> > pa;
	void init(int n){
		pa.resize(n);
		for(int i=0;i<n;i++) pa[i]={i,1};
	}
	pair<int,int> query(int u){
		return (pa[u] = (pa[u].first==u)?(pa[u]):(query(pa[u].first)));
	}
	void join(int a,int b){
		auto ap = query(a);
		auto bp = query(b);
		if(ap.second>bp.second) swap(a,b);
		pa[ap.first].first = bp.first;
		pa[bp.first].second = bp.second+ap.second;
	}
};
