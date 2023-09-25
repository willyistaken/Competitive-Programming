#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
int n;
vector<pair<ll,ll> > arr;


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;	
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr.begin(),arr.end());
	ll maxn =  arr[0].first+arr[0].second;
	ll ans = LONG_LONG_MIN;
	for(int i=1;i<n;i++){
		ans = max(ans,maxn+arr[i].second-arr[i].first);
		maxn = max(maxn+arr[i].second,arr[i].first+arr[i].second);
	}
	for(int i=0;i<n;i++){
		ans = max(ans,arr[i].second);
	}
	cout<<ans<<"\n";
	return 0;
}
