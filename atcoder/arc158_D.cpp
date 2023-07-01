#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

ll n,mod;
ll pow(ll x,ll pow){
	ll r = 1;
	while(pow){
		if(pow &1) r=(r*x)%mod;
		x = (1LL*x*x)%mod;
		pow>>=1;
	}
	return r;
}

void solve(){
	mt19937 mt(time(nullptr));
	cin>>n>>mod;
	ll x,y,z;
	while(true){
		x = mt()%mod;
		y = mt()%mod;
		z = mt()%mod;
		if(x==y || y==z || x==z) continue;
		if(x==0 || y==0 || z==0) continue;
		ll lf = (x+y+z)%mod;
		ll ls = (pow(x,n)+pow(y,n)+pow(z,n))%mod;
		ll lt = (pow(x,2*n)+pow(y,2*n)+pow(z,2*n))%mod;
		ll l = (((lf*ls)%mod)*lt)%mod;
		if(l==0) continue;
		ll r = (pow(x,3*n)+pow(y,3*n)+pow(z,3*n))%mod;
		if(r==0) continue;
		ll t = (r*pow(l,mod-2))%mod;
		x = (t*x)%mod;
		y = (t*y)%mod;
		z = (t*z)%mod;
		if(y<x) swap(y,x);
		if(z<x) swap(z,x);
		if(z<y) swap(y,z);
		cout<<x<<" "<<y<<" "<<z<<"\n";
		return ;
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
