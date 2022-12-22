#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;

int pow(int a,int p){
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
	int n,m;cin>>n>>m;
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans+=pow(m,__gcd(n,i));
		ans%=MOD;
	}
	ans = (ans*pow(n,MOD-2))%MOD;
	cout<<ans<<"\n";
	return 0;
}
