#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

ll get(ll b){
	ll g = b%9;
	ll k = (g*g+g)/2;
	k+=45LL*(b/9);
	return k;
}

void solve(){
	ll l,r;cin>>l>>r;
	cout<<get(r)-get(l-1)<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
