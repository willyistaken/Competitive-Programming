#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> hsh;
vector<int> rhsh;
const int MOD = 998244353;
const int p = 37;
vector<int> ppow;
int getf(int l,int r){
	ll rh = hsh[r];
	ll lh = hsh[l-1];
	ll ans = rh - (1LL*lh*ppow[r-l+1])%MOD;
	ans%=MOD;
	if(ans<0) ans+=MOD;
	return ans;
}

int getb(int l,int r){
	ll lh = rhsh[l];
	ll rh = lhsh[r+1];
	ll ans = lh - (1LL*rh*ppow[r-l+1])%MOD;
	ans%=MOD;
	if(ans<0) ans+=MOD;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int n=  s.size();
	hsh.resize(n+2);
	rhsh.resize(n+2);
	ppow.resize(n+2);
	ppow[0]=1;
	for(int i=1;i<=n;i++){
		ppow[i] = (1LL*ppow[i-1]*p)%MOD;
		hsh[i] = (1LL*hsh[i-1]*p)%MOD;
		hsh[i] = hsh[i]+(s[i-1]-'a');
		if(hsh[i]>MOD) hsh[i]-=MOD;
	}
	for(int i=n;i>=1;i--){
		rhsh[i] = (1LL*rhsh[i+1]*p)%MOD;
		rhsh[i] = (rhsh[i]+(s[i-1]-'a'));
		if(rhsh[i]>MOD) rhsh[i]-=MOD;
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i+=l)
	}
	return 0;
}
