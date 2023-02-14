#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	int a ;cin>>a;
	for(int i=1;i<n;i++){
		int b;cin>>b;
		a = __gcd(a,b);
	}
	if(a==1){
		cout<<0<<"\n";
		return ;
	}
	if(__gcd(a,n)==1){
		cout<<1<<"\n";
		return ;
	}
	if(__gcd(a,n-1)==1){
		cout<<2<<"\n";
		return ;
	}
	cout<<3<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
