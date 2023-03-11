#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	int ans = 1e9;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans = min(ans,__gcd(arr[i],arr[j]));
		}
	}
	if(ans<=2){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}

	
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
