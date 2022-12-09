#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
const int MOD = 1e9+7;

int pow(int a,int k,int m){
	int r = 1;
	while(k){
		if(k&1) r = (1LL*r*a)%m;
		a = (1LL*a*a)%m;
		k>>=1;
	}
	return r;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll numdiv = 1;	
	ll numdivm = 1;
	ll sumdiv = 1;
	ll prodiv = 1;
	int n;cin>>n;	
	while(n--){
		int p,k;cin>>p>>k;
		ll ppow = ((1LL*(k*(k+1)))/2)%(MOD-1);
		ppow = (ppow*numdivm)%(MOD-1);
		prodiv = pow(prodiv,k+1,MOD);
		prodiv = (prodiv*pow(p,ppow,MOD))%MOD;
		numdiv = (numdiv*(k+1))%MOD;
		numdivm = (numdivm*(k+1))%(MOD-1);
		ll o = (pow(p,k+1,MOD)-1)%MOD;
		o = (o*pow(p-1,MOD-2,MOD))%MOD;

		sumdiv = (sumdiv*o)%MOD;
	}
	cout<<numdiv<<" "<<sumdiv<<" "<<prodiv<<"\n";
	return 0;
}
