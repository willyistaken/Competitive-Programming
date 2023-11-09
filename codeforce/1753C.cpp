#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 998244353;
const int N = 2e5+5;
int inv(int a,int p){
	ll r =1;
	while(p){
		if(p&1) r = (a*r)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
void solve(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	int m = 0;
	int cnt = 0;
	for(int i=0;i<n;i++) m+=arr[i];
	for(int i=0;i<n-m;i++) cnt+=arr[i];
	int ans = 0;
	for(int i=1;i<=cnt;i++){
		ll f = (1LL*n*n-n)%MOD;	
		f = (1LL*f*inv(((2LL*i*i)%MOD),MOD-2))%MOD;
		ans = (f+ans)%MOD;
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
