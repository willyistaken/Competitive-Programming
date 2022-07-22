#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	string t;cin>>t;
	vector<string> v;
	for(int i=0;i<t.size()-s.size()+1;i++){
		int error=0;
		for(int j=0;j<s.size();j++){
			if(s[j]!=t[i+j]){
				error++;	
			}
			if(error>1) break;
		}
		if(error<=1){
			string g="";
			for(int k=0;k<s.size();k++){
				g.push_back(t[i+k]);
			}
			v.push_back(g);
		}
	}
	sort(v.begin(),v.end());
	for(auto i : v) cout<<i<<"\n";

	return 0;
}
