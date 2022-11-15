#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int pow(int a,int p,int mod){
	int r = 1;
	while(p){
		if(p&1) r = (1LL*a*r)%mod;
		a = (1LL*a*a)%mod;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	while(n--){
		int a,b,c;cin>>a>>b>>c;
		cout<<pow(a,pow(b,c,1e9+6),1e9+7)<<"\n";
	}

	return 0;
}
