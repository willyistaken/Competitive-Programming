#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
ll n;

bool works(ll k){
	ll bcnt = ((k/2)+k%2);
	ll e = n-bcnt;	
	ll left = k-bcnt;
	return (e-1<=left && left<=(e*(e-1))/2);
}

void solve(){
	cin>>n;
	if(n==1){
		cout<<0<<"\n";
		return ;
	}
	ll l = n-1;ll r = 2*n;
	while(r-l>1){
		ll m = (l+r)/2;
		if(works(m)) l = m;
		else r = m;
	}
	cout<<l<<"\n";
	return ;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	while(q--){
		solve();
	}

	return 0;
}
