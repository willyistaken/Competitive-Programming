#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;

int fac[100005];

void init(){
	fac[0]=1;
	for(int i=1;i<100005;i++){
		fac[i] = (1LL*fac[i-1]*i)%MOD;
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	init();
	while(t--){
		ll n;cin>>n;
		ll ans = (1LL*fac[n]*((1LL*n*n-n)%MOD))%MOD;
		cout<<ans<<"\n";
	}

	return 0;
}
