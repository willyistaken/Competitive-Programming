#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;
int pow(int a,int p){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int mul(int a,int b){
	return (1LL*a*b)%MOD;
}
vector<int> fac(1e6+5);	
vector<int> invfac(1e6+5);

int c(int n,int k){
	if(n<k) return 0;
	return mul(fac[n],mul(invfac[k],invfac[n-k]));
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> p(n+1);
	vector<bool> cnt(n+1);
	for(int i=1;i<=n;i++) cin>>p[i];
	if(n==1){
		cout<<1<<"\n";
		return 0;
	}
	fac[0]=1;
	int pcnt = 0;
	for(int i=1;i<=n;i++) if(p[i]!=i) pcnt++;
	for(int i=1;i<=n+4;i++) {
		fac[i] = (1LL*fac[i-1]*i)%MOD;
	}
	for(int i=0;i<=n+4;i++){
		invfac[i] = pow(fac[i],MOD-2);
	}
	ll ans = mul(fac[n],mul(n,n));
	ans = ans-mul(pcnt,mul(fac[n+1],pow(3,MOD-2)));
	ans%=MOD;
	if(ans<0) ans+=MOD;
	vector<int> sz;														
	for(int i=1;i<=n;i++){
		if(!cnt[i]){
			int cur = i;
			int s = 0;	
			while(!cnt[cur]){
				cnt[cur]=1;
				s++;
				cur = p[cur];
			}
			sz.push_back(s);
		}
	}
	map<int,int> mp;
	for(auto k : sz){
		if(k&1) continue;
		mp[k]++;
	}
	for(auto g : mp){
		int k = g.first;
		int bc = g.second;
		if(k&1) continue;
		k/=2;
		ll fa = mul(k,c(n+1,2*k+1));
		ll sa = (mul(c(n,2*k),n+1)-mul(k,c(n+1,2*k+1)))%MOD;
		if(sa<0) sa+=MOD;
		ans = (ans+mul(bc,mul(mul(fac[n-2*k],mul(2*fac[k],fac[k])),(sa-fa))))%MOD;
	}
	ans%=MOD;
	if(ans<0) ans+=MOD;
	cout<<ans<<"\n";
	return 0;
}


