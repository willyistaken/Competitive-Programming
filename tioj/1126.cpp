#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
bool works(int l,int r){
	while(l<r){
		if(s[l++]!=s[r--]) return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>s){
		int ans=1;
		for(int i=0;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				if(works(i,j)){
					ans=max(j-i+1,ans);
				}
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}
