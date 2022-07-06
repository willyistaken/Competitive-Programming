#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


//doesn't work need to learn suffix tree
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	int dp[n]={0};
	dp[0]=-1;
	int maxn=0;
	for(int i=1;i<n;i++){
		int cur = i-1;
		while(cur>=0){
			if(s[dp[cur]+1]==s[i]){
				dp[i] = dp[cur]+1;
				break;
			}else{
				cur = dp[cur];
			}
		}
		if(cur<0) dp[i]=-1;
		maxn = max(dp[i]+1,maxn);
	}
	cout<<maxn<<"\n";


	return 0;
}
