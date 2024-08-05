#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
void solve(){
	string n; int x;
	cin>>n>>x;
	ll ans = 0;
	for(auto c : n){
		int b = (c-'0');
		if(b>x) b--;
		ans*=9;
		ans+=b;
	}
	cout<<ans+1<<"\n";
	
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	

	return 0;
}
