#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n];
	int temp[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) temp[i]=arr[i];
	int k;cin>>k;
	if(k>31){
		cout<<n<<"\n";
		for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<"\n\n\n-------\n";
		return 0;
	}
	for(int i=0;i<k;i++){
		int a,b;cin>>a>>b;
		arr[a-1]+=arr[b-1];
	}
	bool work = 1;
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1])	{
			work=0;
		}
	}
	if(!work){
		cout<<n<<"\n";
		for(int i=0;i<n;i++) cout<<temp[i]<<" ";
		cout<<"\n\n\n-------\n";
		for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<"\n";
		return 0;
	}
	return 0;
}
