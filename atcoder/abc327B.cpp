#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll b;cin>>b;
	for(ll a=1;a<=15;a++){
		ll r = 1;
		for(int j=0;j<a;j++){
			r*=a;
		}
		if(b==r){
			cout<<a<<"\n";
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;

	return 0;
}
