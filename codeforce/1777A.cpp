#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	int arr[n];
	cin>>arr[0];
	int ans = 0;
	int sum = 0;
	for(int i=1;i<n;i++){
		cin>>arr[i];
		if(arr[i-1]%2==arr[i]%2) sum++;
		else{
			ans+=sum;
			sum= 0;
		}
	}
	ans+=sum;
	cout<<ans<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
