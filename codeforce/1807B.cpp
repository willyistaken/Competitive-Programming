#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	ll esum = 0;
	ll osum = 0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(a%2) osum+=a;
		else esum+=a;
	}
	if(esum>osum) cout<<"Yes\n";
	else cout<<"No\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
