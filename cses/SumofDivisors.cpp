#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 1e9+7;
const int d2 = 5e8+4;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	ll sum = 0;
	for(ll h=1;h<=n;h++){
		ll v = n/h;
		ll r = n/v;
		ll rm = r%MOD;
		ll hm = h%MOD;
		ll rs = (rm*rm+rm)%MOD;
		ll ls = (hm*hm-hm)%MOD;
		rs = (rs*d2)%MOD;
		ls = (ls*d2)%MOD;
		ll nsum = (v*(rs-ls))%MOD;
		sum = (sum+nsum)%MOD;
		h = r;
	}
	if(sum<0) sum+=MOD;
	cout<<sum<<"\n";
	
	return 0;
}
