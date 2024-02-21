#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e9+7;
const int N = 1e6+5;
int deg[N];
vector<int> side[N];
int v[N];
int p2[N];
int pinv2[N];
int g[N];
int pow(int a,int p){
	if(p<0) return 1;
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
int ans = 0;
ll tp = 0;
ll bm = 0;
void dfs(int cur,int p,int dep){
	tp+=v[cur];
	tp%=MOD;
	if(p==0){
		bm = g[deg[cur]-1];
	}else{
		if(deg[cur]>=2) bm = (1LL*bm*g[deg[cur]-2])%MOD;
	}
	for(auto i : side[cur]){
		if(i!=p){
			bm = (1LL*bm*pinv2[deg[i]+dep-1])%MOD;
			tp+=v[i];
		//	cout<<i<<" ";
		//	cout<<tp<<" "<<bm<<" ";
			ans+=(1LL*tp*bm)%MOD;
			ans%=MOD;
			bm = (1LL*bm*p2[deg[i]+dep-1])%MOD;
			tp-=v[i];
			dfs(i,cur,dep+1);
		}
	}
	if(p!=0){
		if(deg[cur]>=2) bm = (1LL*bm*pow(g[deg[cur]-2],MOD-2))%MOD;	
	}
	tp-=v[cur];
	tp%=MOD;
	if(tp<0) tp+=MOD;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	for(int i=2;i<=n;i++){
		int a;cin>>a;
		side[a].push_back(i);
		side[i].push_back(a);
		deg[i]++;
		deg[a]++;
	}
	p2[0]=1;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n+3;i++){
		p2[i] = (2LL*p2[i-1])%MOD;
	}
	pinv2[n+3] = pow(p2[n+3],MOD-2);
	for(int i=n+2;i>=0;i--) pinv2[i] = (2LL*pinv2[i+1])%MOD;
	for(int i=0;i<=n;i++){
		g[i] = (1LL*(p2[i+1]-1)*pinv2[i])%MOD;
		g[i] = (1LL*g[i]*pow(i+1,MOD-2))%MOD;
	}
	for(int i=1;i<=n;i++){
		tp=0;
		bm=0;
		ans=0;
		dfs(i,0,1);
		//cout<<ans<<"\n";
		ans+=(1LL*v[i]*pinv2[deg[i]])%MOD;
		ans%=MOD;
		cout<<ans<<"\n";
	}

	return 0;
}
