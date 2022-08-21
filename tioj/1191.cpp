#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#include<bits/extc++.h>
//__gnu_pbds::


// 9-base to 10 base converter


int main(){
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	while(cin>>s){
		if(s[0]=='0') return 0;
		ll ans=0;
		for(auto i : s){
			int dig = i-'0';
			if(dig>=6) dig--;
			ans*=9;
			ans+=dig;
			if(ans<0) cout<<"no";
		}
		cout<<ans<<"\n";
	}
}

