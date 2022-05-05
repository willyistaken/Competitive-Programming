#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];

	}
	sort(arr,arr+n);
	long long sum=0;
	for(int i=0;i<(n>>1);i++){
		sum+=arr[i]	;
	}
	cout<<sum<<endl;
}
