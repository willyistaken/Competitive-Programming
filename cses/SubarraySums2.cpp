#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int a;cin>>a;
	ll sum[n+1];
	for(int i=1;i<=n;i++) cin>>sum[i];
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	map<ll,int> s;
	ll ans = 0;
	for(int i=0;i<=n;i++){
		ans+=s[sum[i]-a];	
		s[sum[i]]++;
	}
	cout<<ans<<"\n";
	return 0;
}

