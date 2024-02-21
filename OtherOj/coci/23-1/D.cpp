#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e9+7;
const int N = 5005;

int dp[N][N];
int sum[N];


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;	
	dp[2][n-1]=2;
	for(int i=3;i<=n;i++){
		sum[n-1] = dp[i-1][n-1];
		for(int j=n-2;j>0;j--){
			sum[j] = (sum[j+2]+dp[i-1][j])%MOD;
		}
		for(int j=n-2;j>0;j--){
			dp[i][j] = sum[j+1];
			if(i+j>n) continue;
			dp[i][j] = (dp[i][j]+sum[i+j-1])%MOD;
		}
	}
	ll ans = 0;
	for(int i=2;i<=min(n,k);i++){
		for(int j=1;j<n;j++){
			ans  = (ans+(1LL*dp[i][j]*(k-i+1))%MOD)%MOD;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
