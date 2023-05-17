#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<ll> sum(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	vector<int> dp(n+1,0);
	vector<int> from(n+1,0);
	for(int i=1;i<=n;i++){
		from[i]	 = max(from[i],from[i-1]);
		dp[i] = dp[from[i]]+1;
		int to = lower_bound(sum.begin(),sum.end(),2*sum[i]-sum[from[i]])-sum.begin();
		if(to<=n) from[to] = max(from[to],i);
	}
	cout<<dp[n]<<"\n";
	return 0;
}
