#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const string ans = "rwxrwxrwx";
void solve(){
	string s;cin>>s;
	for(int i=0;i<3;i++){
		int a = (s[i]-'0');
		for(int j=0;j<3;j++){
			if((a>>(2-j))&1) cout<<ans[3*i+j];
			else cout<<'-';
		}
	}
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
