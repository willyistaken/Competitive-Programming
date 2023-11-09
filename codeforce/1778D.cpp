#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e6+5;
const int MOD = 998244353;
int f[N];
int pow(int a,int p){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
void solve(){
	int n;cin>>n;
	f[0]=0;
	f[1] = pow(2,n)-1;
	if(f[1]<0) f[1]+=MOD;
	for(int i=2;i<=n;i++){
		int x= i-1;
		f[x+1] = (1LL*(f[x]-1)*n)%MOD;
		f[x+1] = (1LL*f[x+1]*pow(n-x,MOD-2))%MOD;
		int mi = (1LL*pow(n-x,MOD-2)*((1LL*x*(f[x-1]))%MOD))%MOD;
		f[x+1] = (MOD+f[x+1]-mi)%MOD;
	}
	string a,b;cin>>a>>b;
	int cnt = 0;
	for(int i=0;i<n;i++) if(a[i]!=b[i]) cnt++;
	cout<<f[cnt]<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
