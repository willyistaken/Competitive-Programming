#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int minn = 1e9;
	for(auto i : s){
		minn =min(minn,i-'a');
	}
	for(int i=n-1;i>=0;i--){
		if(s[i]-'a'==minn){
			cout<<s[i];
			for(int j=0;j<i;j++) cout<<s[j];
			for(int j=i+1;j<n;j++) cout<<s[j];
			cout<<"\n";
			return ;
		}
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
