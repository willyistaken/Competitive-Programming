#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

const int MAXN = 205;
ll dp[MAXN][MAXN][2];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,K;cin>>n>>K;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<int> d = arr;
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=0;i<n;i++) arr[i] = lower_bound(d.begin(),d.end(),arr[i]) -d.begin();
	int m = d.size();
	for(int h=0;h<m;h++){
		for(int i=0;i<n;i++){
			if(arr[i]>h) dp[i][h][1] = ((i)?(min(dp[i-1][h][1],(ll)1e18)):(1e18));
			else dp[i][h][1] = (i)?(min(dp[i-1][h][1],(ll)d[h]-d[arr[i]])):(d[h]-d[arr[i]]);
			dp[i][h][1] = min(dp[i][h][1],((h)?(dp[i][h-1][1]):(ll(1e18))));
		}
	}
	for(int k=2;k<=K;k++){
		for(int h=0;h<m;h++){
			for(int i=0;i<n;i++){
				if(arr[i]>h) dp[i][h][k&1] =  (i)?(dp[i-1][h][k&1]):(1e18);
				else dp[i][h][k&1] = (i)?(min(dp[i-1][h][(k+1)&1]+d[h]-d[arr[i]],dp[i-1][h][k&1])):(1e18);
				dp[i][h][k&1] = min(dp[i][h][k&1],((h)?(dp[i][h-1][k&1]):((ll)(1e18))));
			}
		}
	}
	ll ans = LONG_LONG_MAX;
	for(int h = 0;h<m;h++){
		ans = min(ans,dp[n-1][h][K&1]);
	}
	cout<<ans<<"\n";
	return 0;
}
