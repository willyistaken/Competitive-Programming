#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int dp[n+1] ={0};
	dp[0]=0;
	dp[1]=0;
	dp[2] = 1;
	for(int i=3;i<=n;i++){
		ll ans = (1LL*(i-1)*(dp[i-1]+dp[i-2]))%MOD;
		dp[i] = ans;
	}
	cout<<dp[n]<<"\n";
	return 0;
}
