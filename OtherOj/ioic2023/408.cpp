#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 998244353;

ll inv(ll a){
	a%=MOD;
	ll r = 1;
	ll p = MOD-2;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;
	ll a;cin>>a;
	ll sum = a;
	for(int i=1;i<n;i++){
		ll b;cin>>b;
		sum+=b;
	}
	ll ssum = sum;
	ll m;cin>>m;
	for(int i=0;i<m;i++){
		ll b;cin>>b;
		ssum+=b;
	}
	ll k = __gcd(sum,ssum);
	sum/=k;
	ssum/=k;
	ll tp =a*ssum;
	ll g =__gcd(tp,sum);
	tp/=g;
	sum/=g;
	tp%=MOD;
	sum%=MOD;
	cout<<(tp*inv(sum))%MOD<<"\n";
	return 0;
}
