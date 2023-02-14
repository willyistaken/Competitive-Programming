#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	ll ans = 0;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i) ans+=abs(arr[i]-arr[i-1]);
	}
	for(int i=0;i<n;i++){
		ll minn = 1e18;
		int minp = -1;
		for(int j=0;j<n;j++){
			ll mo = ans;
			ll totlost = 0;
			if(i) totlost+=abs(arr[i]-arr[i-1]);
			if(i!=n-1) totlost+=abs(arr[i]-arr[i+1]);
			if(j) totlost+=abs(arr[j]-arr[j-1]);
			if(j!=n-1) totlost+=abs(arr[j]-arr[j+1]);
			swap(arr[i],arr[j]);
			if(i) totlost-=abs(arr[i]-arr[i-1]);
			if(i!=n-1) totlost-=abs(arr[i]-arr[i+1]);
			if(j) totlost-=abs(arr[j]-arr[j-1]);
			if(j!=n-1) totlost-=abs(arr[j]-arr[j+1]);
			mo-=totlost;
			swap(arr[i],arr[j]);
			if(mo<minn){
				minn = mo;
				minp = j;
			}
		}
		cout<<minp+1<<" ";
	}
	cout<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
