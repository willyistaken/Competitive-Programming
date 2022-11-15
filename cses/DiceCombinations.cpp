#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int dp[n+1];
	memset(dp,0,sizeof(dp));	
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=6;k++){
			if(i-k<0) break;
			else dp[i] = (dp[i]+dp[i-k])%MOD;
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}
