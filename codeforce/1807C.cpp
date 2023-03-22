#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int works[26];

void solve(){
		int n;cin>>n;
		string s;cin>>s;
		for(int i=0;i<26;i++)	works[i]=0;
		for(int i=0;i<n;i++){
			if(!works[s[i]-'a']){
				works[s[i]-'a'] = (i%2)+1;
			}else{
				if((i%2)+1!=works[s[i]-'a']){
					cout<<"No\n";
					return ;
				}
			}
		}
		cout<<"Yes\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
