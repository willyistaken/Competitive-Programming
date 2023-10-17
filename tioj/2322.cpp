#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 5005;
int A[N];
int B[N];
int C[N];
const int MOD= 998244353;
ll dp[2][N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) cin>>B[i];
	for(int i=1;i<=n;i++) cin>>C[i];
	for(int i=0;i<N;i++) dp[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int k=0;k<N;k++){
			dp[i&1][k]=0;
			int l = max(k-A[i]+B[i],0);
			int r = min(k-A[i]+C[i],N-1);
			if(l<=r){
				dp[i&1][k]=(dp[i&1][k]+dp[!(i&1)][r])%MOD;
				if(l) dp[i&1][k]=(dp[i&1][k]-dp[!(i&1)][l-1])%MOD;
			}
			if(k) dp[i&1][k] = (dp[i&1][k]+dp[i&1][k-1])%MOD;
		}
	}
	if(dp[n&1][N-1]<0) dp[n&1][N-1]+=MOD;
	cout<<dp[n&1][N-1]<<"\n";
	return 0;
}
