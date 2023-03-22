#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n,q;cin>>n>>q;
	vector<ll> sum(n+1,0);
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		sum[i]=sum[i-1]+a;
	}
	while(q--){
		ll l,r,k;cin>>l>>r>>k;
		ll ans = sum[n];
		ans-=sum[r]-sum[l-1];
		ans+=(r-l+1)*k;
		if(ans%2){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
