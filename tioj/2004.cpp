#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

int power(int p){
	int f=4;
	int r=1;
	while(p){
		if(p&1) r = (1LL*r*f)%MOD;
		f = (1LL*f*f)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int k;cin>>k;
		cout<<power(k-1)<<"\n";
	}

	return 0;
}
