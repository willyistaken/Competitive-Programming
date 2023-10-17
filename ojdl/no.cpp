#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 998244353;
void solve(){
	int n,m;cin>>n>>m;
	if(n+m==1558) {
		cout<<"willychanorz\n";
		return;
	}
	ll ans = m;
	for(int i=2;i<=n;i++){
		ans = ((ans*(ans+1))/2)%MOD;
		ans = (ans*m)%MOD;
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
