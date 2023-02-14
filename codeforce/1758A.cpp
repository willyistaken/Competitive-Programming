#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		cout<<s;
		for(int i = s.size()-1;i>=0;i--) cout<<s[i];
		cout<<"\n";
	}

	return 0;
}
