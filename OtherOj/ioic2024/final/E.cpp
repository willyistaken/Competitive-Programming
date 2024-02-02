#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
const int MOD = 998244353;
vector<int> side[N];

int po(int a,int p){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;	
		p>>=1;
	}
	return r;
}
int sz[N];
int P[N];
vector<pair<int,int> > edge;
void dfs(int a,int p){
	sz[a]=1;
	for(auto i : side[a]){
		if(i!=p){
			dfs(i,a);
			sz[a]+=sz[i];
			P[i]=a;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;	
	for(int i=0;i<n-1;i++)	{
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
		edge.push_back({a,b});
	}
	dfs(1,0);
	P[1]=0;
	ll ans = 0;	
	for(auto i : edge){
		int a=  i.first;
		int b = i.second;
		if(b==P[a]) swap(a,b);
		ans= (ans+(ll)po((2LL*sz[b]*(n-sz[b]))%MOD,k))%MOD;
	}
	for(int i=1;i<=n;i++){
		ll sqsum = 0;	
		ll sum = 0;
		for(auto u : side[i]){
			if(u==P[i]){
				sqsum= (sqsum+po((n-sz[i]),2*k))%MOD;
				sum = (sum+po(n-sz[i],k))%MOD;
			}else{
				sqsum= (sqsum+po(sz[u],2*k))%MOD;
				sum = (sum+po(sz[u],k))%MOD;
			}
		}
		sqsum= ((1LL*sum*sum%MOD)-sqsum)%MOD;
		sqsum = 1LL*sqsum*po(2,k-1)%MOD;
		if(sqsum<0) sqsum+=MOD;
		ans = (ans-sqsum)%MOD;
		if(ans<0) ans+=MOD;
	} 
	if(ans<0) ans+=MOD;
	cout<<ans<<"\n"	;
	return 0;
}
