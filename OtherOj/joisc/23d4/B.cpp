#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	int ans = 0;
	int ans2=0;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n-1;i++){
		ans2+=max(arr[i],arr[i+1]);
	}
	int k = unique(arr,arr+n)-arr;
	for(int i=0;i<k-2;i++) {
		if(arr[i]>arr[i+1] && arr[i+1]<arr[i+2]){
			ans2-=min(arr[i],arr[i+2]);
			ans2+=arr[i+1];
		}
	}
	for(int i=0;i<m;i++){
	 int u,v;cin>>u>>v;
	}
	cout<<ans2<<"\n";	
	return 0;
}
