#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds

struct edge{
	int a,b;
	ll w;
	edge(int _a,int _b,ll _w){
		a = _a;
		b = _b;
		w = _w;
	}
};
const int N = 2e5+5;
int P[N];
ll a[N];
vector<edge> edgeset;
int query(int x){
	if(P[x]==x) return x;
	return P[x]=query(P[x]);
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	for(int i=1;i<=n;i++) P[i]=i;
	pair<ll,int> minn = {1e18,0};
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) minn = min(minn,{a[i],i});
	for(int i=1;i<=n;i++) edgeset.push_back(edge(i,minn.second,minn.first+a[i]));
	for(int i=0;i<m;i++){
		int u,v;
		ll w;cin>>u>>v>>w;
		edgeset.push_back(edge(u,v,w));
	}
	sort(edgeset.begin(),edgeset.end(),[](const edge &u,const edge &v){return u.w<v.w;});
	ll ans = 0;	
	for(auto e : edgeset){
		if(query(e.a)!=query(e.b)){
			ans+=e.w;
			P[query(e.a)]=query(e.b);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
