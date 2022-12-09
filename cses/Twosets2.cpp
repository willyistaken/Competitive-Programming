#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 1e9+7;

int dp[505][127765];	
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int v= 0;v<=(i*i+i)/2;v++){
			if(v-i>=0) dp[i][v]=(dp[i][v]+dp[i-1][v-i])%MOD;
			if(v+i<127265) dp[i][v]=(dp[i][v]+dp[i-1][v+i])%MOD;
			if(v+i!=i-v && i-v>=0) dp[i][v]=(dp[i][v]+dp[i-1][i-v])%MOD;
		}
	}
	cout<<dp[n][0]<<"\n";
	// dp[i][v] = dp[i-1][v-i]+dp[i-1][v+i]+dp[i][i-v];
	return 0;
}
