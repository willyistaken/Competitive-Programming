#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 1e9+7;
int dp[100005][102];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int a;cin>>a;
	if(a) dp[0][a]=1;
	else fill(dp[0],dp[0]+m+1,1);
	dp[0][0]=0;
	dp[0][m+1] = 0;
	for(int i=1;i<n;i++){
		int a;cin>>a;
		for(int v=1;v<=m;v++){
			if(a && v!=a)dp[i][v] = 0;
			else dp[i][v] = (1LL*dp[i-1][v]+dp[i-1][v-1]+dp[i-1][v+1])%MOD; 
		}
	}
	ll ans = 0;
	for(int i=1;i<=m;i++) ans=(ans+dp[n-1][i])%MOD;
	cout<<ans<<"\n";
	return 0;
}
