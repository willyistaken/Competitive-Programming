#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	ll n,x;cin>>n>>x;
		if(n==x){
			cout<<n<<"\n";
			return ;
		}
		if(n==0){
			cout<<-1<<"\n";
			return;
		}
	ll k = n;	
	while(k){
		n+=(n&-n);
		k&=n;
		if(k==x){
			cout<<n<<"\n";
			return;
		}
	}
	cout<<-1<<"\n";
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
