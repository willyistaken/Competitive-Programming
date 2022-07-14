#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	getline(cin,s);
	string t;
	getline(cin,t);

	int dp[s.size()+1][t.size()+1] = {{0}};
	dp[0][0] = (s[0]==t[0]) ? 0:1;
	for(int i=0;i<=s.size();i++){
		for(int j=0;j<=t.size();j++){
			if(min(i,j)==0) dp[i][j] = max(i,j);
			else{
				dp[i][j] = min( { dp[i-1][j]+1 , dp[i][j-1]+1 , dp[i-1][j-1]+((s[i-1]==t[j-1])?0:1) } );
			}
		}
	}
	cout<<dp[s.size()][t.size()]<<"\n";
	return 0;
}
