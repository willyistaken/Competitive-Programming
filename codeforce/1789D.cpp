#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

string act(string s,int b){
	if(b==0) return s;
	string ans = s;
	if(b<0){
		b = -b;
		for(int i=0;i+b<s.size();i++){
			if(s[i]=='1') ans[i+b] =(ans[i+b]=='1')?('0'):('1');
		}
	}else{
		for(int i=0;i+b<s.size();i++){
			if(s[i+b]=='1') ans[i] = (ans[i]=='1')?('0'):('1');
		}
	}
	
	return ans;
}

void solve(){
	vector<int> out;
	int n;cin>>n;
	string s,t;cin>>s>>t;
	bool hasoa = 0;
	int firsto = -1;
	for(int g=n-1;g>=0;g--){
		if(s[g]=='1') {hasoa = 1;firsto = g;}
	}
	bool hasob = 0;
	for(auto c : t){
		if(c=='1') hasob=1;
	}
	if(hasoa!=hasob) {cout<<"-1\n"; return ;}
	for(int i=0;i<n;i++){
		if(s[i]!=t[i]){
			s = act(s,firsto-i);
			cout<<s<<"\n";
			if(firsto-i) out.push_back(firsto-i);
			if(s[i]=='1') firsto = min(firsto,i);
		}
	}
	cout<<out.size()<<"\n";
	if(out.size()!=0){
		for(auto i : out) cout<<i<<" ";
		cout<<"\n";
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
