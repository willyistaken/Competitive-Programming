#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin >> s){
		int leaf,ans,depth,count[100000];
		leaf=ans=depth=0; memset(count,0,sizeof(count));
		int dn=1;
		for(auto c:s){
			if(c=='*') count[dn]++,leaf++;
			else if(c=='(') count[dn++]++;
			else count[dn--]=0;
			if(dn>1) ans=max(ans,count[dn]); depth=max(depth,dn);
		}
		cout << leaf << ' ' << depth << ' ' << ans << '\n';
	}
    return 0;
}

