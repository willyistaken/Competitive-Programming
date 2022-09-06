#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		if(n<=2*k) cout<<"First\n";
		else{
			if((n-(2*k+1))%(k+1)){
				cout<<"First\n";
			}else{
				cout<<"Second\n";
			}
		}
	}

	return 0;
}
