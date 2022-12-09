#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int dp[n+1] = {0};
	dp[1]=1;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<n;j++){
			dp[j+1] = (s[j]=='*')?(0):((dp[j+1]+dp[j])%MOD);
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}
