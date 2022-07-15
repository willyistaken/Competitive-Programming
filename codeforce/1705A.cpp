#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,x;cin>>n>>x;
		int arr[2*n];
		for(int i=0;i<2*n;i++) cin>>arr[i];
		sort(arr,arr+2*n);
		bool flag=1;
		for(int i=0;i<n;i++){
			if(arr[i+n]-arr[i]<x){
				flag=0;
				break;
			}

		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}

	return 0;
}
