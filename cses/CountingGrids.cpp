#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


/*
	rotate 90:
			2^(((n)^2+2+(n%2))/4);
	rotate 180:
		2^(2n^2 + 8 -6(n%2));
	rotate 270:
		the same as 90
	rotate 360:
		2^(n*n);
*/

const int MOD = 1e9+7;

int pow(ll p){
	int a = 2;
	int r = 1;
	while(p){
		if(p&1) r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n;cin>>n;	
	if(n==1){
		cout<<2<<"\n";
		return 0;
	}
	ll ans = 0;
	ll p90 = (n%2)?((n+3)*(n-1)/4 - (n-1)/2 + 1):(n*(n+2)/4 - n/2);
	ll p180 = (n%2)?((n+3)*(n-1)/2 - (n-1) + 1):(n*(n+2)/2 - n);
	ans += 2*pow(p90);
	ans%=MOD;
	ans+=pow(p180);
	ans%=MOD;
	ans+=pow(n*n);	
	ans%=MOD;
	ans = (ans*250000002)%MOD;
	cout<<ans<<"\n";
	return 0;
}
