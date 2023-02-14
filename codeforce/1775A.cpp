#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	string s;cin>>s;
	if(s.size()<=2) {
		cout<<":(\n";
		return ;
	}
	int pos = 0;
	for(int i=1;i<s.size()-1;i++){
		if(s[i]=='a'){
			pos = i;
			break;
		}
	}
	if(pos){
		for(int i=0;i<pos;i++) cout<<s[i];
		cout<<" ";
		cout<<s[pos]<<" ";
		for(int i=pos+1;i<s.size();i++) cout<<s[i];
		cout<<"\n";
		return ;
	}else{
		cout<<s[0]<<" ";
		for(int i=1;i<s.size()-1;i++) cout<<s[i];
		cout<<" "<<s[s.size()-1]<<"\n";
		return ;
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
