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
	ll sum = 1;
	for(int i=0;i<n;i++){
		if(arr[i]>sum){
			cout<<sum<<"\n";
			return 0;
		}else{
			sum+=arr[i];
		}
	}
	cout<<sum<<"\n";

	return 0;
}
