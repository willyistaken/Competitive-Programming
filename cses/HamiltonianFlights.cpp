#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e9+7;
int dp[(1<<20)][20];
vector<int> side[20];
int n,m;
int DP(int mask,int v){
	if(!(mask&1)) return 0;
	if(mask==1) return 1;
	if(dp[mask][v]) return dp[mask][v];
	if(!((mask>>v)&1)) return 0;
	int nmask  = mask-(1<<v);
	ll ans = 0;	
	for(auto p : side[v]){
		if((nmask>>p)&1) ans=(ans+DP(nmask,p))%MOD;
	}
	return (dp[mask][v] = ans);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		side[b].push_back(a);
	}
	cout<<DP((1<<n)-1,n-1)<<"\n";
	return 0;
}
