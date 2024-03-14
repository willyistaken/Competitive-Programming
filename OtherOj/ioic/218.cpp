#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	ll l=0;ll r=1e6+5;
	while(r-l>1){
		ll m =(l+r)/2;
		if(m*m>n) r = m;
		else l = m;
	}
	ll ans = (1LL*((n-l)%MOD)*((n-l+1)%MOD))%MOD;
	ans = 1LL*ans*((ll)5e8+4)%MOD;;
	for(ll i=2;i<=l;i++){
		ll now = i;
		int cnt = 0;
		while(now<=n && now>0){
			ll nnow = now*i;
			nnow = min(nnow,n+1);
			cnt++;
			ans+=(1LL*cnt*((nnow-now)%MOD))%MOD;
			ans%=MOD;
			now = nnow;
			if(now>n) break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
