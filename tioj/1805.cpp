#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	ll arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+n+1);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans,min(arr[i]-arr[1],arr[n]-arr[i]));
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
