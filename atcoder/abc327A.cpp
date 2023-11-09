#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	string s;cin>>s;
	for(int i=0;i<n-1;i++){
		if(s[i]=='a' && s[i+1]=='b'){
			cout<<"Yes\n";
			return 0;
		}
		if(s[i]=='b' && s[i+1]=='a'){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}
