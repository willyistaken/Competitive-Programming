#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,l;cin>>n>>l;
	pair<int,int> arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
		arr[i].second = -arr[i].second;
	}
	sort(arr,arr+n);
	ll noww = l;
	ll r=0;
	for(int i=n-1;i>=0;i--){
		if(noww-arr[i].second>l){
			r+=arr[i].first;	
			noww = -arr[i].second;
		}else{
			noww-=arr[i].second;
		}
	}
	cout<<r<<"\n";
	return 0;
}
