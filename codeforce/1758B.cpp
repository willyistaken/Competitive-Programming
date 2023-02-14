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
		if(n&1){
			for(int i=0;i<n;i++) cout<<1<<" ";
			cout<<"\n";
		}else{
			cout<<"1 3 ";
			for(int i=0;i<n-2;i++) cout<<2<<" ";
			cout<<"\n";
		}
	}

	return 0;
}
