#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	const int mod = 1e9+7;
	int a = 2;
	int r  = 1;
	while(n){
		if(n&1) r = (1LL*a*r)%mod;
		a = (1LL*a*a)%mod;
		n>>=1;
	}
	cout<<r<<"\n";

	return 0;
}
