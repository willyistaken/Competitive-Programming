#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


ll power(int a,int p,int MOD){
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
	int n,x;cin>>n>>x;
	int k = power(2,n,10006);	
	int g = power(x,k,10007);
	cout<<g<<"\n";

	return 0;
}
