#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int w,b,n;cin>>w>>b>>n;
		int a[n],d[n];
		for(int i=0;i<n;i++) cin>>a[i]>>d[i];
		int m;cin>>m;
		ll dp[w] = {0};
		ll maxn = 0;
		for(int i=0;i<n;i++){
			for(int j=1;j<w;j++){
				if(j>=a[i]+m) dp[j] = max(dp[j-a[i]-m]+d[i],dp[j]);
				maxn = max(maxn,dp[j]);
			}
		}
		cout<<((maxn>=b)?("Yes\n"):("No\n"));
	}

	return 0;
}
