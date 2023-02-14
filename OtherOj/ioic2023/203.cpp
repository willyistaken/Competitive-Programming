#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 998244353;

ll pow(int a,int p){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m;cin>>m;
	string s;cin>>s;	
	int q;cin>>q;
	while(q--){
		ll n;cin>>n;
		n = (n-m)%MOD;
		int bom = pow(10,m);	
		
	}


	return 0;
}
