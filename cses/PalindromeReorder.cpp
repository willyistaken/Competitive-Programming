#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int cnt[26];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	for(auto i : s) cnt[i-'A']++;
	int oc=0;
	int stuff = 0;
	for(int i=0;i<26;i++) {
		if(cnt[i]%2){
			oc++;
			stuff = i;
			if(oc>1){ cout<<"NO SOLUTION\n";
			return 0;
			}
		}
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<cnt[i]/2;j++){
			cout<<(char)('A'+i);
		}
	}
	if(oc){
		cout<<(char)('A'+stuff);
	}
	for(int i=25;i>=0;i--){
		for(int j=0;j<cnt[i]/2;j++){
			cout<<(char)('A'+i);
		}
	}
	cout<<"\n";

	return 0;
}
