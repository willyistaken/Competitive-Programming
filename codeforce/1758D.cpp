#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	ll n;cin>>n;
	ll k = 2*n;	
	ll sum = k*k-k;
	ll a = 0;
	if((n-2)%2){
		ll h = (n-3)/2;	
		a = h*k+n;
	}else{
		ll h = (n-2)/2;
		a = h*k;
	}
	ll j = (sum-a)/n;
	if(n%2){
		cout<<j<<" "<<j+k<<' ';			
		for(int i=1;i<=(n-3)/2;i++){
			cout<<j+i<<" "<<j+k-i<<" ";								
		}
		cout<<j+n<<"\n";
	}else{
		cout<<j<<" "<<j+k<<' ';
		for(int i=1;i<=(n-2)/2;i++){
			cout<<j+i<<" "<<j+k-i<<" ";
		}
		cout<<"\n";
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
