#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 10007;

int dp[5]={0};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int n = s.size();
	string t = " fool";	
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=4;j>=1;j--){
			if(s[i]==t[j]){
				dp[j]=(dp[j]+dp[j-1])%MOD;
			}
		}
	}
	cout<<dp[4]<<'\n';
	return 0;
}
