#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> zal(string s){
	vector<int> z(s.size(),0);
	for(int i=1,l=0,r=0;i<s.size();i++){
		if(r>=i) z[i] = min(z[i-l],r-i+1);
		while(i+z[i]<s.size()&&s[z[i]]==s[i+z[i]]) z[i]++;
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
	return z;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b;cin>>a>>b;
	string s = b+"#"+a;
	vector<int> z = zal(s);
	int cnt = 0;
	for(int i=b.size();i<s.size();i++){
		if(z[i]==b.size()) cnt++;	
	}
	cout<<cnt<<"\n";
	return 0;
}
