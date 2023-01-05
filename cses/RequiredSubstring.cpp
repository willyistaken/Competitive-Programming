#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int dp[1005][105];	
const int MOD = 1e9+7;
int N;
string s;
vector<int> fail;
int ans(int n,int m){
	if(dp[n][m]>=0) return dp[n][m];
	if(n==N && m!=s.size()) return 0;
	if(n==N && m==s.size()) return 1;
	if(m==s.size()) return (26LL*ans(n+1,m))%MOD;
	ll r  = 0;	
	for(int i=0;i<26;i++){
		int k = m;			
		while(s[k]!=(char)('A'+i) && k>0){
			k = fail[k-1];			
		}
		if(s[k]==(char)('A'+i)) k++;
		r+=ans(n+1,k);
		r%=MOD;
	}
	dp[n][m] = r;
	return dp[n][m];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>N;	
	cin>>s;
	int m = s.size();
	fail.resize(m,0);	
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<m;i++){
		int j = fail[i-1];
		while(j>0 && s[j]!=s[i]){
			j = fail[j-1];
		}
		if(s[j]==s[i])  j++;
		fail[i] = j;
	}
	//for(int i=0;i<m;i++) cout<<fail[i]<<" ";
	//cout<<"\n";
	cout<<ans(0,0)<<"\n";	
	return 0;
}
