#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


string s;
vector<int> hsh;
const int MOD = 1e9+7;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	hsh.push_back(0);
	int t;cin>>t;
	int head = 1;
	while(t--){
		bool b;cin>>b;
		if(b){
			int l = 0;	
		}else{
			string g;cin>>g;
			s+=g;
			for(;head<=s.size();head++){
				hsh.push_back((17LL*hsh[head-1])%MOD+(s[head-1]-'a'))%MOD;
			}
		}
	}

	return 0;
}
