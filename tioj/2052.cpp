#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int cnt[58];
int psum[58];
int MOD ;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>MOD;
	string s;cin>>s;
	for(auto c:s){
		psum[c-'A']++;
	}
	for(int i=1;i<58;i++){
		psum[i]+=psum[i-1];
	}
	vector<int> arr;
	for(auto c : s){
		int g = c-'A';
		arr.push_back((g)?(psum[g-1]+cnt[g]):(cnt[g]));
		cnt[g]++;
	}
																		
	return 0;
}
