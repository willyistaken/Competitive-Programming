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
		if(n==5){
			cout<<"1 2 3 4 5\n";
			continue;
		}
		if(n&1){
			cout<<n-1<<" "<<n-2<<" ";
			for(int i=n-4;i>=3;i--) cout<<i<<" ";
			cout<<1<<" "<<2<<" "<<n-3<<" "<<n<<"\n";
		}else{
			for(int i=n-2;i>=1;i--) cout<<i<<" ";
			cout<<n-1<<" "<<n<<"\n";
		}
	}

	return 0;
}
