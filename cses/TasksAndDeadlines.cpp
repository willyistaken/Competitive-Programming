#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	pair<int,int> arr[n];	
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+n);
	ll time = 0;
	ll ans = 0;
	for(int i=0;i<n;i++){
		time+=arr[i].first;
		ans+=arr[i].second-time;
	}
	cout<<ans<<"\n";
	return 0;
}
