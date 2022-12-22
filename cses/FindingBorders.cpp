#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> zal(string &s){
	vector<int> z(s.size(),0);
	for(int i=1,l=0,r=0;i<s.size();i++){
		if(r>=i) z[i] = min(z[i-l],r-i+1);	
		while(i+z[i]<s.size() && s[i+z[i]]==s[z[i]]) z[i]++;
		if(i+z[i]-1>r) l = i,r = i+z[i]-1;
	}
	return z;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	vector<int> z = zal(s);
	for(int i=s.size()-1;i>=1;i--){
		int suffixlen= s.size()-i;
		if(z[i]==suffixlen){
			cout<<suffixlen<<" ";
		}
	}
	cout<<"\n";
	return 0;
}
