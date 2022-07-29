#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
bitset<10005> vis;
bool dp[10005];
void dfs(int r,vector<vector<int>> &side){
	vis[r]=1;
	bool ans=1;
	for(auto i : side[r]){
		if(!vis[i]) dfs(i,side);
		ans&=!dp[i];
	}
	dp[r]=ans;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n>>m && (n||m)){
	vis.reset();
	memset(dp,0,sizeof(dp));
	vector<vector<int>> side(n+1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
	}
	dp[n]=1;
	vis[n]=1;
	string s;cin>>s;
	dfs(1,side);
//	for(int i=1;i<=n;i++) cout<<i<<" "<<dp[i]<<"\n";
	string name[2]={"Mimi\n","Moumou\n"};

	cout<<name[dp[1]^(s[1]=='i')];


	}

	return 0;
}
