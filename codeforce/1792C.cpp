#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;
vector<int> arr;
bool check(int k){
	int prev = 0;
	for(int i=0;i<n;i++){
		if(arr[i]<=k || arr[i]>=n-k+1) continue;
		if(arr[i]<prev) return 0;
		prev = arr[i];
	}
	return 1;
}

void solve(){
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	int l = -1;int r = n/2;
	while(r-l>1){
		int m = (r+l)/2;
		if(check(m)) r = m;
		else l = m;
	}
	cout<<r<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
