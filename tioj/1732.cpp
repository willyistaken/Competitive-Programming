#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		nth_element(arr,arr+(n/2),arr+n);
		int k=arr[n/2];
		ll ans=0;
		for(int i=0;i<n;i++){
			ans += abs(arr[i]-k);
		}
		cout<<ans<<"\n";
	}
//this is just the median
	return 0;
}
