#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<vector<pair<int,int> > side;
vector<ll> dis;

map<pair<int,int>,int> > es;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	side.resize(n+q+1);
	dis.resize(n+q+1,1e18);
	for(int i=0;i>m;i++){
		int a,b,w;cin>>a>>b>>w;
		if(a>b) swap(a,b);
		es[make_pair(a,b)]=w;
	}
	
	for(int i=1;i<=q;i++){
		int t,a,b,x;cin>>t>>a>>b>>x;
		pair<int,int> edgepair = {min(a,b),max(a,b)};
		dis[n+i]=t;
		int w = es[edgepair];
		if(a<b) w -=x;
		else 
	}

	return 0;
}
