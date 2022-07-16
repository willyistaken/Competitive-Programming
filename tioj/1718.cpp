#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	int m,n,p;cin>>m>>n>>p;
	int w[n][p];
	int v[n][p];
	for(int i=0;i<n;i++){
		for(int j=0;j<p;j++){
			cin>>w[i][j]>>v[i][j];
		}
	}
	int dp[m+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=m;j>=0;j--){
			for(int k=0;k<p;k++){
				if(j>=w[i][k] && dp[j]<dp[j-w[i][k]]+v[i][k]) dp[j]=dp[j-w[i][k]]+v[i][k];
			}
		}
	}
	cout<<dp[m]<<"\n";
	return 0;
}
