#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int x,y,z;cin>>x>>y>>z;
		if(!x && !y){
			cout<<-1<<"\n";
		}else if(x>10000){
			cout<<0<<"\n";
		}else if(!z){
			if(x) cout<<0<<"\n";
			else cout<<1<<"\n";
		}else{
			cout<<((10000-x)*1LL*z)/(1LL*y*z+10000) + 1<<"\n";
		}
	}

	return 0;
}
