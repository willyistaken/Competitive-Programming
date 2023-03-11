#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
void solve(){
	int n,k;cin>>n>>k;
	ll s[n+1];
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]+=s[i-1];
	}
	ll w[k+2];	
	w[0]=0;
	w[k+1] = 1e18;
	for(int i=1;i<=k;i++) cin>>w[i];
	int dp[n+1][n+1];		
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = k+1;
		}
	}
	for(int i=0;i<=n;i++){
		dp[i][i]=0;
	}
	for(int l=1;l<n;l++){
		for(int i=1;i+l<=n;i++){
			for(int b=1;b<=k+1;b++){
												
			}
		}
	}
	if(dp[1][n]<=k) cout<<"Yes\n";
	else cout<<"No\n";
}


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
