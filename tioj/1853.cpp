#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int dp[n][2];
	string s;
	cin>>s;
	dp[0][0] = (s[0]=='1');
	dp[0][1] = (s[0]=='0');
	for(int i=1;i<n;i++){
		dp[i][1] = (s[i]=='1') ? (dp[i-1][1]):min((dp[i-1][0]+1),(dp[i-1][1]+1));
		dp[i][0] = (s[i]=='1') ? min((dp[i-1][1]+1),(dp[i-1][0]+1)):(dp[i-1][0]);

	}
	cout<<dp[n-1][1]<<endl;
	return 0;
}
