#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int k;cin>>k;
	pair<ll,ll> arr[n];
	for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
	vector<ll> ans;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans.push_back(abs(arr[i].first-arr[j].first)+abs(arr[i].second-arr[j].second));
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<k;i++) cout<<ans[i]<<"\n";

	return 0;
}
