#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	ll dp[n+1][7];
	memset(dp,0,sizeof(dp));	
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int k = 0;k<6;k++){
			dp[i][k] = (dp[i-1][k]+dp[i-1][max(k+1,6)]+dp[i-1][max(k+2,6)]+dp[i-1][max(k+3,6)]+dp[i-1][max(k+4,6)]+dp[i-1][max(k+5,6)])%MOD;
			cout<<dp[i][k]<<" ";
		}
		cout<<"\n";
	}
	cout<<dp[n][0]<<"\n";
	return 0;
}
