#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll l = 0;
	ll r = 1e12;
	ll pos = 0;
	ll lap = 0;
	ll lappos = 0;
	while(r-l>1){
		ll mid = (l+((r-l)/2));
		cout<<"? "<<pos+mid-lappos<<endl;
		ll x;cin>>x;
		if(lap!=pos+mid-lappos-x){
			r = mid;
		}else{
			l = mid;
		}
		l = max(l,x);
		lap = pos+mid-lappos-x;
		pos = pos+mid-lappos;
		lappos = x;
	}
	cout<<"! "<<r<<endl;
	return 0;
}
