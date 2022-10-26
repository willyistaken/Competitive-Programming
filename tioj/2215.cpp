#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int ans = 0;
pair<int,int> dp[100005];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=2;i<=n;i++){
		int p;cin>>p;
		dp[p].second = max({dp[p].first+(dp[i].first+1),dp[p].second,dp[i].second});
		dp[p].first = max(dp[i].first+1,dp[p].first);
		ans = max(ans,dp[p].second);
		cout<<ans<<"\n";
	}

	return 0;
}
