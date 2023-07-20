#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n,k;cin>>n>>k;
	ll arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<ll> dif;
	for(int i=0;i<n-1;i++){
		dif.push_back(abs(arr[i]-arr[i+1]));
	}
	sort(dif.begin(),dif.end());
	ll ans = 0;
	for(int i=0;i<n-k;i++){
		ans+=dif[i]	;
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
