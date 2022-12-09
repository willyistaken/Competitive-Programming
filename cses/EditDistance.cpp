#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int dp[5005][5005];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b;cin>>a>>b;
	int n = a.size();int m = b.size();
	for(int i=0;i<5005;i++) {
		dp[0][i]=i;
		dp[i][0]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
		}
	}
	cout<<dp[n][m]<<"\n";
	return 0;
}
