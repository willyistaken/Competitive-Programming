#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> s(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i] +=s[i-1];
	}
	vector<vector<ll> > dp(n+1,vector<ll>(n+1,-1e15));
	for(int l=0;l<n;l++) dp[l][l+1]=0;
	for(int l = 0;l+2<=n;l++){
		dp[l][l+2] = (s[l+1]-s[l])*(s[l+2]-s[l+1]);
	}
	for(int d = 3;d<=n;d++){
		for(int l = 0;(l+d)<=n;l++){
			for(int k = l+1;k<(l+d);k++){
				dp[l][l+d] = max(dp[l][k]+((s[k]-s[l])*(s[l+d]-s[k])),dp[l][l+d]);	
				dp[l][l+d] = max(dp[k][l+d]+((s[k]-s[l])*(s[l+d]-s[k])),dp[l][l+d]);
			}
		}
	}
	cout<<dp[0][n]<<"\n";

	return 0;
}
