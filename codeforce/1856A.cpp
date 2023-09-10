#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int s=-1;
	for(int i=n-1;i>=1;i--){
		if(arr[i]<arr[i-1])	{s = i-1;break;}
	}
	int maxn = 0;
	for(int i=s;i>=0;i--){
		maxn = max(maxn,arr[i]) ;
	}
	cout<<maxn<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
