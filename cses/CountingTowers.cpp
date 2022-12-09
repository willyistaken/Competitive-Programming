#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int N = 1e6+5;

int dp[N][2];
const int MOD=  1e9+7;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	dp[1][0]=1;
	dp[1][1]=1;
	for(int i=2;i<N;i++){
		dp[i][0] = (4LL*dp[i-1][0]+dp[i-1][1])%MOD;
		dp[i][1] = (2LL*dp[i-1][1]+dp[i-1][0])%MOD;
	}
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<(dp[n][0]+dp[n][1])%MOD<<"\n";
	}

	return 0;
}
