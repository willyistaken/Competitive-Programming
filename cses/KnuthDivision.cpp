#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 5005;
ll sum[N];
pair<ll,int> dp[N][N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	for(int i=1;i<n;i++){
		dp[i][i+1] = {sum[i+1]-sum[i-1],i};
	}
	for(int l=3;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j = i+l-1;	
			int u = dp[i][j-1].second;
			int d = dp[i+1][j].second;
			dp[i][j] = {1e18,1e18};
			for(int k = u;k<=d;k++){
				dp[i][j] = min({dp[i][k].first+dp[k+1][j].first,k},dp[i][j]);
			}
			dp[i][j].first+=sum[j]-sum[i-1];
		}
	}
	cout<<dp[1][n].first<<"\n";
	return 0;
}
