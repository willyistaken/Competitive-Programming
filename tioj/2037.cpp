#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
vector<int> match;
vector<bool> vis;
vector<vector<int> > side;

bool dfs(int cur){
	for(auto i : side[cur]){
		if(vis[i]) continue;
		vis[i]=1;
		if(!match[i] || dfs(match[i])){
			match[i] = cur;
			return 1;
		}
	}
	return 0;
}

vector<pair<int,int>> ans;

void dfs2(int cur){
	vis[cur]=1;	
	int sum0 = 0;
	int sum1 = 0;
	for(auto i : side[cur]){
		if(vis[i]) continue;
		dfs2(i);
		sum0+=ans[i].second;
		sum1+=min(ans[i].first,ans[i].second);
	}
	ans[cur].first = sum0;
	ans[cur].second = sum1+1;
}

void solve2(int p,int q,int k){
	int n = p+q+1;			
	side.resize(n);
	for(int i=0;i<=n;i++) side.clear();
	ans.resize(n,{0,0})	;
	vis.resize(p+q+1);
	fill(vis.begin(),vis.end(),0);
	for(int i=0;i<k;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(p+b);
		side[p+b].push_back(a);
	}
	dfs2(1);
	cout<<min(ans[1].first,ans[1].second)<<"\n";
}

void solve(){
	int p,q,k;cin>>p>>q>>k;
	if(p>1500 || q>1500){
		solve2(p,q,k);
		return ;
	}
	match.resize(q+1);	
	vis.resize(q+1);
	fill(match.begin(),match.end(),0);
	fill(vis.begin(),vis.end(),0);
	side.resize(p+1);
	for(int i=0;i<=p;i++) side.clear();
	for(int i=0;i<k;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
	}
	for(int i=1;i<=p;i++){
		fill(vis.begin(),vis.end(),0);
		dfs(i);
	}
	int cnt = 0;
	for(int i=1;i<=q;i++){
		if(match[i]) cnt++;
	}
	cout<<cnt<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
