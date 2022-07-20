#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int inv(int n){
	int  p = MOD-2;
	int r=1;
	while(p){
		if(p & 1) r = 1LL*r*n%MOD;
		n = 1LL*n*n%MOD;
		p>>=1;
	}
	return r;
}
const int MAXN = 5e5+7122;
int c[MAXN];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	c[1]=1;
	for(int i=2;i<=MAXN;i++){
		c[i] = 1LL*c[i-1]*(4*i-2)%MOD;
		c[i] = 1LL*c[i]*inv(i+1)%MOD;
	}
	int t;cin>>t;
	while(t--){
		int b;cin>>b;
		b>>=1;
		cout<<c[b]<<"\n";
	}
	return 0;
}

// Cn = Cn-1*(4n-2)/(n+1);
