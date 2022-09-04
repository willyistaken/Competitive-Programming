#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		bool flag=0;
		for(int i=0;i<n;i++){
			if(a[i]>b[i]){
				flag=1;
				break;
			}
			if(a[i]<b[i]){
				if(!(b[i]-1<=b[(i+1)%n])){
					flag=1;
					break;
				}
			}
		}
		if(flag) cout<<"No\n";
		else cout<<"Yes\n";
	}

	return 0;
}
