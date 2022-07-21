#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int A,n;cin>>A>>n;
	int dp[A+1];
	memset(dp,0,sizeof(dp));
	int w[n+1],v[n+1];
	for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
	int MAXN = 0;
	for(int i=1;i<=n;i++){
		for(int j=A;j>=0;j--){
			if(j>=w[i]){
				dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
				MAXN = max(MAXN,dp[j]);
			}
		}
	}
	for(int i=0;i<=A;i++){
		if(dp[i]==MAXN){
			cout<<MAXN<<" "<<i<<"\n";
			return 0;
		}
	}

	return 0;
}
