#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

void solve(){
	ll n,k;cin>>n>>k;
	vector<ll> ans;
	for(int i=1;i<=n;i++){
		cout<<(1LL<<(i))<<endl;
		ll m9;cin>>m9;
		m9%=9;
		ans.push_back(m9);
	}
	cout<<36<<endl;
	for(int i=1;i<=n;i++){
		ll mod = (9*(1LL<<(i+2)));
		cout<<((1*inv(9,(1LL<<(i+2)))%mod*9LL%mod)+(ans[i-1]*inv((1LL<<(i+2)),9)%mod*(1LL<<(i+2))%mod))%mod<<" ";
	}
	cout<<endl;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
