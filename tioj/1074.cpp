#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bitset<450> vis;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n && n){
		vis.reset();
		int arr[n+1]={0};
		for(int i=1;i<=n;i++){
			int k;cin>>k; 
			arr[i] = arr[i-1]+k;
		}
		if(arr[n]==n){
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				vis[arr[j]-arr[i]]=1;
			}
		}
		bool pass=1;
		for(int i=1;i<=arr[n];i++){
			if(!vis[i]){
				cout<<"NO\n";
				pass=0;
				break;
			}
		}
		if(pass) cout<<"YES\n";
	}

	return 0;
}
