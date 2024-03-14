#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

//https://oeis.org/A057693
// a(n)=Sum_i=0...k-1;P(n-1,i)*a(n-i-1) where P(x,i) x!/(x-i)!

const int MOD = 998244353;
const int N = 1e6+5;
int fac[N];
int invfac[N];
int po(int a,int p){
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
	int n,k;cin>>n>>k;
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i] = (1LL*fac[i-1]*i)%MOD;
	}
	invfac[n] = po(fac[n],MOD-2);
	for(int i=n-1;i>=0;i--){
		invfac[i] = (1LL*invfac[i+1]*(i+1))%MOD;
	}
	vector<int> a(n+1,0);
	vector<ll> presum(n+1,0);
	for(int i=0;i<=min(k,n);i++){
		a[i] = fac[i];
		presum[i] = (1LL*a[i]*invfac[i])%MOD;
		if(i) presum[i] = (presum[i-1]+presum[i])%MOD;
	}
	if(k>=n){
		cout<<a[n]<<"\n";
		return 0;
	}
	for(int i=k+1;i<=n;i++){
		int r = i-1;
		int l = i-k;
		ll p = 0;
		if(l) p = presum[r]-presum[l-1];
		else p = presum[r];
		p%=MOD;
		if(p<0) p+=MOD;
		a[i]=((1LL*fac[i-1]*p)%MOD)%MOD;
		presum[i] = (1LL*a[i]*invfac[i])%MOD;
		if(i) presum[i] = (presum[i-1]+presum[i])%MOD;
	}
	cout<<a[n]<<"\n";
	return 0;
}
