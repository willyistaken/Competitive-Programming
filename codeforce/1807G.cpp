#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	if(arr[0]!=1){
		cout<<"No\n";
		return ;
	}
	ll sum = 1;	
	for(int i=1;i<n;i++){
		if(sum<arr[i]){
			cout<<"No\n";
			return;
		}
		sum+=arr[i];
	}
	cout<<"Yes\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
