#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int W;cin>>W;
	int w[n],v[n];
	for(int i=0;i<n;i++) cin>>w[i];
	for(int i=0;i<n;i++) cin>>v[i];
	int dp[W+1] = {0};
	for(int i=0;i<n;i++){
		for(int h=W;h>=w[i];h--){
			dp[h] = max(dp[h],dp[h-w[i]]+v[i]);
		}
	}
	cout<<dp[W]<<"\n";

	return 0;
}
