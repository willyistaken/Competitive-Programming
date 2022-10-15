#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


ll phi(ll k){
	ll r = k;
	for(ll p = 2;p*p<=k;p++){
		if(k%p==0){
			while(k%p==0) k/=p;

			r-= r/p;
		}
	}
	if(k>1) r-=r/k;
	return r;
}
ll n,m;
ll pow(ll p){
	ll r = 1;
	ll a = n;
	while(p){
		if(p & 1) r = (r*a)%m;
		a = (a*a)%m;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n>>m){
		ll d = __gcd(pow(m),m);
		ll l = -1;ll r = m;
		while(r-l>1){
			ll mid = l +((r-l)/2);
			if(__gcd(pow(mid),m)==d) r = mid;
			else l = mid;
		}
		ll x0 = l+1;
		ll start = pow(x0);
		ll p = phi(m);
		ll mincycle = p;
		for(ll i = 1;i<=sqrt(p);i++){
			if(p%i==0){
				if(pow(x0+i)==start) {
					mincycle = min(mincycle,i);
					break;
				}
				if(pow(x0+(p/i))==start) mincycle = min(mincycle,p/i);
			}
		}
		cout<<x0<<" "<<mincycle<<"\n";
	}
	return 0;
}


/*
idea now: use the fact the gcd will be stable, binary search for x, and use the fact that phi(m) must be a mutiple of p, search for p;
too slow, I guess the bottle neck is at phi and factor (sqrt(n)...)
*/
