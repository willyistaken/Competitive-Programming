#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<int> arr;
	int sum = 0;
	for(int i=0;i<n;i++){
		int a;cin>>a;	
		arr.push_back(a-sum);
		sum = a;
	}
	ll l=0;ll r = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>=0) r+=arr[i]+1;
	}
	ll minn = max(l,r);
	for(int i=0;i<n;i++){
		if(arr[i]<=0){
			l+=1-arr[i];
		}
		if(arr[i]>=0){
			r-=arr[i]+1;
		}
		minn = min(minn,max(l,r));
	}
	cout<<minn<<"\n";
	return 0;
}
