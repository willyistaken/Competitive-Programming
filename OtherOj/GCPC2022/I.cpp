#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	ll c[n+1];
	c[n]=0;
	ll dp[n+1]={0};
	for(int i=0;i<=n;i++) dp[i] = LONG_LONG_MAX;
	vector<ll> v[n+1];
	for(int i=0;i<n;i++){
		cin>>c[i];
		v[i].resize(m,0);
		for(int j=0;j<min(m,n-i);j++) cin>>v[i][j];
	}
	dp[0] = c[0];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(m,i);j++){
			dp[i] = min(dp[i],dp[i-j]-v[i-j][j-1]+c[i]);
		}
	}
	cout<<dp[n]<<"\n";
	
	return 0;
}
