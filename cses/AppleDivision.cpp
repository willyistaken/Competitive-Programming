#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int w[n];
	ll ans = 1e18;
	for(int i=0;i<n;i++) cin>>w[i];
	for(int i=0;i<(1<<n);i++){
		ll a = 0;
		ll b = 0;
		for(int j=0;j<n;j++){
			if((i>>j)&1) a+=w[j];
			else b+=w[j];
		}
		ans = min(ans,abs(a-b));
	}
	cout<<ans<<"\n";

	return 0;
}
