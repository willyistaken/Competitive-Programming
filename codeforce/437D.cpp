#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<pair<int,int>> p;

pair<int,int> query(int a) {
	return (p[a] = ((p[a].first==a)?(p[a]):(query(p[a].first))));
}

void join(int a,int b){
	int totalsize = query(a).second+query(b).second;
	if(query(a).second>query(b).second) swap(a,b);
	p[query(a).first] = p[query(b).first];
	p[query(b).first].second = totalsize;
}





int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	p.resize(n);
	for(int i=0;i<n;i++) p[i] = {i,1};
	int w[n];
	for(int i=0;i<n;i++) cin>>w[i];
	vector<int> con[n];
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		if((w[a]==w[b])?(a<b):(w[a]>w[b])) swap(a,b);
		con[a].push_back(b);	
	}
	int order[n];
	for(int i=0;i<n;i++) order[i] = i;
	stable_sort(order,order+n,[&](const int a,const int b){return w[a]>w[b];});
	ll ans = 0;	
	for(int i=0;i<n;i++){
		int u = order[i];
		for(auto v : con[u]){
			if(query(u).first!=query(v).first){
				ans+= 1LL*w[u]*query(u).second*query(v).second;
				join(u,v);
			}
		}
	}
	cout<<fixed<<2*(double)ans/(double)(1LL*n*(n-1))<<"\n";
	return 0;
}
