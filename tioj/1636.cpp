#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	if(n==1){
		int a;cin>>a;
		cout<<1LL*((k+1)/2)*a<<"\n";
		return 0;
	}
	ll ans=0;
	int arr[n];
	ll presum = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		presum+=arr[i];
		if(!i) {
			ans = arr[0];
			continue;
		}
		ll stuff = k-i;
		if(stuff<=0){
			ans = max(ans,presum);
			break;
		}
		ans = max(ans,presum+1LL*((stuff+1)/2)*arr[i-1]+1LL*(stuff/2)*arr[i]);
	}
	cout<<ans<<"\n";


	return 0;
}
