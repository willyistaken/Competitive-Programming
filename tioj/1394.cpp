#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
pair<int,int> dp[32772];
vector<int> side[32772];

void dfs(int p){
	dp[p].first = 0;dp[p].second = 1;
	for(auto i : side[p]){
		dfs(i);
		dp[p].first+=dp[i].second;	
		dp[p].second+=min(dp[i].first,dp[i].second);
	}
	//cout<<p<<" "<<dp[p].first<<" "<<dp[p].second<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i = 0;i<n;i++){
		int m;cin>>m;
		for(int j = 0;j<m;j++){
			int a;cin>>a;
			side[i].push_back(a);
		}
	}
	dfs(0);
	cout<<min(dp[0].first,dp[0].second)<<"\n";
	return 0;
}
