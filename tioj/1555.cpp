#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	short n,m;cin>>n>>m;
	ll cnt=0;
	int maxnans=0;
	int dp[m+1][2];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=1;j<=m;j++){
			if(s[j-1]=='1') dp[j][i%2]=0;
			else{
				dp[j][i%2] = min({dp[j-1][i%2],dp[j][(i+1)%2],dp[j-1][(i+1)%2]})+1;
			}
			cnt+=dp[j][i%2];
			maxnans = max(maxnans,dp[j][i%2]);
		}
	}
	cout<<cnt<<" "<<maxnans<<"\n";
	return 0;
}
