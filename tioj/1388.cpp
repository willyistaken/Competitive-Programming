#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][105]={0};
ll DP(int l,int r){
	if(dp[l][r]) return dp[l][r];
	ll maxn = LONG_LONG_MIN;
	if((r-l+1)%2){
		for(int i=l;i<r;i++){
			maxn = max(maxn,DP(l,i)*DP(i+1,r));
		}
	}else{
		for(int i=l;i<r;i++){
			maxn = max(maxn,DP(l,i)+DP(i+1,r));
		}
	}
	dp[l][r] = maxn;
	return dp[l][r];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		for(int i=0;i<105;i++){
			for(int j=0;j<105;j++) dp[i][j]=0;
		}
		for(int i=0;i<n;i++){
			cin>>dp[i][i];
		}
		cout<<DP(0,n-1)<<"\n";	
	}
	return 0;
}
