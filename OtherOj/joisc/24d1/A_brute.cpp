#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	ll D;cin>>D;
	vector<ll> arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i];
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		ll cur = arr[r];
		ll ans = 0;
		for(int i=r-1;i>=l;i--){
			ll g = arr[i];
			if(g>cur){
				ll dif = g-cur;
				ll f = (dif+D-1)/D;
				ans+=f;
				g-=f*D;
			}
			cur=g;
		}
		if(cur<0) cout<<-1<<"\n";
		else cout<<ans<<"\n";
	}
	

	return 0;
}
