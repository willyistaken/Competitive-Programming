#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	while(cin>>n>>k){
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		nth_element(arr,arr+k-1,arr+n,greater<int>());
		cout<<arr[k-1]<<"\n";
	}

	return 0;
}
