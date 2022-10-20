#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 998244353;
bitset<300005> notprime;
void init(){
	notprime.reset();
	notprime[1]=1;
	for(int i=2;i<300005;i++){
		if(!notprime[i]){
			for(int j = 2*i;j<300005;j+=i){
				notprime[j]=1;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	ll n,m;cin>>n>>m;	
	ll ans = 0;
	ll pow = 1;
	ll primemul=1;
	ll powmprime=1;
	for(int i=1;i<=n;i++){
		pow = ((__int128)pow*m)%MOD;
		if(!notprime[i] && primemul<=m) primemul*=i;
		powmprime = ((__int128)powmprime*(m/primemul))%MOD;
		ans += (pow-powmprime);
		ans%=MOD;
		if(ans<0) ans+=MOD;
	}
	cout<<ans<<"\n";
	return 0;
}
