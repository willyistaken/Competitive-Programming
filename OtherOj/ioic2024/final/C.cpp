#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

#define int ll

ll get(ll b) {
    b = abs(b);
    ll l = -1;
    ll r = 2e9;
    while(r-l>1) {
        ll m = (l+r)/2;
        if(m*(m+1)/2>=b){
			r = m;
		}
		else l = m;
    }
	if((r*(r+1)/2-b)&1){
		if(((r+2)*(r+1)/2-b)&1)	{
			return r+2;
		}else{
			return r+1;
		}
	}else{
		return r;
	}
}


void solve() {
    ll n,k;
    cin>>n>>k;
    cout<<min(get(k),get(k-n))<<"\n";
}


signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}
