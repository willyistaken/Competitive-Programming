#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int MOD = 998244353;
int pow(int a,int p){
	if(p<0){
		a = pow(a,MOD-2);
		p = -p;
	}
	ll r = 1;
	while(p){
		if(p&1) r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
const int N = 1e6+5;
int fac[N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i] = (1LL*fac[i-1]*i)%MOD;
	int t;cin>>t;	
	while(t--){
		int n,k;cin>>n>>k;
		ll ans = (k+1);
		ans = ans*fac[n-2]%MOD;
		ans = ans*pow(fac[n-k-1],MOD-2)%MOD;
		ans = ans*pow(n,n-k-2)%MOD;
		cout<<ans<<"\n";
	}
	
	return 0;
}

