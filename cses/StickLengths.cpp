#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	int sum = arr[n/2];
	ll ans = 0;
	for(int i=0;i<n;i++) ans+=abs(arr[i]-sum);	

	cout<<ans<<"\n";

	return 0;
}
