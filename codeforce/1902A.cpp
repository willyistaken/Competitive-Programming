#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n;cin>>n;
	string s;cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0') {
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
	return ;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
