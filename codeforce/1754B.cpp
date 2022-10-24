#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		if(n==3) {
			cout<<"1 2 3\n";
			continue;
		}
		if(n==2){
			cout<<"1 2\n";
			continue;
		}
		int x = n/2+1;
		cout<<x<<" ";
		if(n%2){
			for(int i=1;i<=n/2;i++) cout<<i<<" "<<x+i<<" ";
			cout<<"\n";
		}else{
			for(int i=1;i<n/2;i++) cout<<i<<" "<<x+i<<" ";
			cout<<x-1<<"\n";
		}
	}

	return 0;
}
