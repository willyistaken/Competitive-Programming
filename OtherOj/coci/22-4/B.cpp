#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int dp[5005][5005];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> a1(n+1);
	for(int i=1;i<=n;i++) cin>>a1[i];
	int m;cin>>m;
	vector<int> a2(m+1);
	for(int i=1;i<=m;i++) cin>>a2[i];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i || j) dp[i][j]=1e9;
			if(i){
				dp[i][j]= min(dp[i-1][j]+1+((a1[i]&1)==(dp[i-1][j]&1)),dp[i][j]);
			}
			if(j){
				dp[i][j]= min(dp[i][j-1]+1+((a2[j]&1)==(dp[i][j-1]&1)),dp[i][j]);
			}
		}
	}
	cout<<dp[n][m]<<"\n";
	return 0;
}
