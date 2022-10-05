#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	pair<ll,int> arr[n];
	for(int i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		arr[i].first= (x*x + y*y);
		cin>>arr[i].second;
		arr[i].second = -arr[i].second;
	}
	sort(arr,arr+n);
	int maxh = 0;
	int ans= 0;
	for(int i=0;i<n;i++){
		ans = max(ans,maxh+arr[i].second);
		maxh = max(maxh,-arr[i].second);
	}
	cout<<ans<<"\n";
	return 0;
}


