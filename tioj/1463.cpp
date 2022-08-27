#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	while(cin>>s && s[0]!='0'){
		ll dp[s.size()+1]={0};
		dp[0]=1;
		s = ' '+s;
		for(int i=1;i<s.size();i++){
			if(s[i]!='0') dp[i]+=dp[i-1];
			if(s[i-1]=='1' || (s[i-1]=='2'&&s[i]<='6')) dp[i]+=dp[i-2];
		}
		cout<<dp[s.size()-1]<<"\n";
	}

	return 0;
}
