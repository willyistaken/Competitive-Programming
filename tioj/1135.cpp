#include<bits/stdc++.h>
using namespace std;
typedef long long ll;





ll mie(ll n,ll m,ll ns,ll nr,ll ms,ll mr){
    if((n*ms+m*mr)==0) return ns;
    int time= (n*ns+m*nr)/(n*ms+m*mr);
    return mie(n,m,ms,mr,ns-(time*ms),nr-(time*mr));
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		ll a,b,c,k;cin>>a>>b>>c>>k;
		ll MOD = (1LL<<k);
		ll rhs = (b-a)%MOD;
		if(rhs<0) rhs+=MOD;
		if(c==0){
			cout<<((a==b)?"0":"FOREVER")<<"\n";
			continue;
		}
		if(rhs%__gcd(c,MOD)!=0) {
			cout<<"FOREVER\n";
			continue;
		}
		if(rhs%c==0){
			cout<<(rhs/c)%MOD<<"\n";
			continue;
		}
		int inv = mie(c,MOD,1,0,0,1);
		inv%=MOD;
		if(inv<0) inv+=MOD;
		cout<<(rhs*inv)%MOD<<"\n";

	}
	return 0;
}
