#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	int arr[n+1][32];
	for(int i=1;i<=n;i++) cin>>arr[i][0];
	for(int j=1;j<32;j++){
		for(int i=1;i<=n;i++){
			arr[i][j] = arr[arr[i][j-1]][j-1];
		}
	}
	while(q--){
		int a,k;cin>>a>>k;
		for(int i=0;i<32;i++){
			if((k>>i) & 1) {
				a = arr[a][i];	
			}
		}
		cout<<a<<"\n";
	}
	return 0;
}
