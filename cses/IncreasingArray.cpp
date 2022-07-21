#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int maxn = arr[0];
	ll ans=0;
	for(int i=1;i<n;i++){
		if(arr[i]<maxn){
			ans+=(maxn-arr[i]);
		}
		maxn = max(maxn,arr[i]);
	}
	cout<<ans<<"\n";

	return 0;
}
