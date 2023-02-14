#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int cnt[26];
int n;
string s,t;

bool check(int g){
	for(int i=0;i<n&&g<n;i++){
		if(t[i]==s[g]) g++;
	}
	return (g==n);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>s>>t;
	for(auto i : s) cnt[i-'a']++;
	for(auto i : t) cnt[i-'a']--;
	for(int i=0;i<26;i++){
		if(cnt[i]!=0){
			cout<<"-1\n";
			return 0;
		}
	}
	int l = -1;int r = n-1;
	while(r-l>1){
		int m = (l+r)/2;
		if(check(m)) r= m;
		else l = m;
	}
	cout<<r<<"\n";
	return 0;
}
