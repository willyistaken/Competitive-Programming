#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	ll n,P,l,t;cin>>n>>P>>l>>t;
	ll task = ((n-1)/7)+1;
	if(P<=(task*t)+l*((task+1)/2)){
		ll days = (P+(l+2*t)-1)/(l+2*t);
		cout<<n-days<<"\n";
		return ;
	}else{
		P-=(task*t)+l*((task+1)/2);	
		ll days = (task+1)/2;
		days+=(P+l-1)/l;
		cout<<n-days<<"\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
