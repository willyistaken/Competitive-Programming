#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int ans=1;
	int now=1;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]) now++;
		else now=1;
		ans = max(now,ans);
	}
	cout<<ans<<"\n";

	return 0;
}
