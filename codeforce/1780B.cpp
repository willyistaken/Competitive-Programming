#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	ll sum[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	ll ans = 0;
	for(int i=1;i<n;i++){
		ans = max(ans,__gcd(sum[i],sum[n]-sum[i]));
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
