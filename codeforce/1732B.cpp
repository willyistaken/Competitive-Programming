#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	vector<int> dp[2];
	dp[0].resize(n,0);
	dp[1].resize(n,0);
	dp[0][n-1]=(s[n-1]=='0');
	dp[1][n-1]=(s[n-1]=='1');
	for(int i=n-2;i>=0;i--){
		dp[0][i] = (s[i]=='1')?(dp[0][i+1]):(dp[1][i+1]+1);
		dp[1][i] = (s[i]=='0')?(dp[1][i+1]):(dp[0][i+1]+1);
	}
	int ans = 1e9;		
	int sum = 0;
	for(int i=0;i<n;i++){
		ans = min(ans,sum+dp[sum%2][i]);	
		char comp = (sum%2)?('0'):('1');
		if(s[i]==comp) sum++;
	}
	ans = min(ans,sum);
	cout<<ans<<"\n";
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
