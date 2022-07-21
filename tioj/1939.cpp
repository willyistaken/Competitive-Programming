#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;
const int MOD = 1e9+9;
int dp[MAXN];
void init(){
	dp[1]=1;
	dp[2]=4;
	int sum=1;
	for(int i=3;i<MAXN;i++){
		dp[i] = (3LL*dp[i-1] + 2LL*sum + 1LL)%MOD;
		sum = (sum+dp[i-1])%MOD;
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<dp[n]<<"\n";
	}

	return 0;
}
