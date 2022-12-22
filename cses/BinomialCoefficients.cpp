#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD  =1e9+7;
const int V = 1e6+5;
int fac[V];

int inv(int a){
	int p  =MOD-2;
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
	fac[0]=1;
	for(int i=1;i<V;i++){
		fac[i] = (1LL*fac[i-1]*i)%MOD;		
	}
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		int k = (1LL*fac[b]*fac[a-b])%MOD;
		k = inv(k);
		cout<<(1LL*k*fac[a])%MOD<<"\n";
	}
	return 0;
}
