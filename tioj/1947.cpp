#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
vector<vector<int> > side;
int ans,n;
bitset<1000005> vis;
int dfs(int r){
	vis[r]=1;
	int down=0;
	int maxn=0;
	for(auto i : side[r]){
		if(!vis[i]){
			int k = dfs(i);
			down+=k;
			maxn = max(maxn,k);
		}
	}
	maxn = max(n-1-down,maxn);
	ans = min(maxn,ans);
	return down+1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	ans = INT_MAX;
	vis.reset();
	side.resize(n);
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(0);
	cout<<ans<<"\n";

	return 0;
}
