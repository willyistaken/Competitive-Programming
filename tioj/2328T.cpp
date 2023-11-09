#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,p;cin>>n>>k>>p;
	ll ans = 0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		ans+=a;
	}
	cout<<ans<<"\n";
	return 0;
}
