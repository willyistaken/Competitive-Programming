#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		cout<<s[i];
	}
	for(int i=s.size()-2;i>=0;i--){
		cout<<s[i];
	}
	cout<<"\n";
	return 0;
}
