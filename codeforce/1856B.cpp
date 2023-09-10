#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	if(n==1){
		int a;cin>>a;
		cout<<"No\n";
		return ;
	}
	int arr[n];
	ll sum = 0;
	ll minpos = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i]	;
		sum+=arr[i];
		if(arr[i]==1) minpos+=2;
		else minpos+=1;
	}
	if(minpos>sum) cout<<"No\n";
	else cout<<"Yes\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
