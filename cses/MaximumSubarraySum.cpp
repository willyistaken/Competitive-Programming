#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	ll sum = -1e18;
	ll ans = LONG_LONG_MIN;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		sum = max(sum+a,(ll)a);
		ans = max(sum,ans);
	}
	cout<<ans<<"\n";

	return 0;
}
