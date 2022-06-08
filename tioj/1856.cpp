#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n,greater<int>());
		ll maxn=0;
		ll sum=0;
		for(int i=0;i<n;i++){
			sum+=arr[i];
			maxn= max(sum-((1LL*(i+1)*(i+2))/2),maxn);
		}
		cout<<maxn<<"\n";

	}
	return 0;
}
