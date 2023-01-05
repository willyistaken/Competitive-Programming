#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> zal(string &s){
	int n = s.size();
	vector<int> z(n,0);
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r) z[i] = min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
		if(i+z[i]-1>r) l = i,r = i+z[i]-1;
	}
	return z;
}

vector<int> kmp(string &s){
	int n = s.size();
	vector<int> p(n,0);
	for(int i=1;i<n;i++){
		int j = p[i-1];
		while(j && s[j]!=s[i]){
			j = p[j-1];
		}
		if(s[j]==s[i]) j++;
		p[i]= j;
	}
	return p;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	for(auto i : zal(s)) cout<<i<<" ";
	cout<<"\n";
	for(auto i : kmp(s)) cout<<i<<" ";
	cout<<"\n";
	return 0;
}
