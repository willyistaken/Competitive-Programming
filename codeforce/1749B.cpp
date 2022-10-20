#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		ll ans=0;
		for(int i=0;i<n;i++){
			int a;cin>>a;
			ans+=a;
		}
		int maxn = 0;
		for(int i=0;i<n;i++){
			int b;cin>>b;
			ans+=b;
			maxn = max(maxn,b);
		}
		ans-=maxn;
		cout<<ans<<"\n";
	}

	return 0;
}
