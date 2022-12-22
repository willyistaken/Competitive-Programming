#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e9+7;

int inv(int a){
	int r = 1;
	int p = MOD-2;
	while(p){
		if(p&1) r = (1LL*a*r)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n%2){
		cout<<0<<"\n";
		return 0;
	}
	n/=2;
	ll a=1;
	for(int i=1;i<=n;i++){
		a = (1LL*a*(4*i-2))%MOD;
		a  = (1LL*a*inv(i+1))%MOD;
	}
	cout<<a<<"\n";
	return 0;
}
