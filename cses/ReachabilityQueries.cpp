#pragma GCC target("popcnt")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> ord;
vector<int> side[50001];
int vis[50001];
int t;
int low[50001];
bool instk[50001];
stack<int> stk;
int scc[50001];
int g;
void dfs(int cur){
	vis[cur]=low[cur]=++t;
	instk[cur]=1;	
	stk.push(cur);
	for(auto i : side[cur]){
		if(!vis[i]) dfs(i);
		if(instk[i]) low[cur] = min(low[cur],low[i]);
	}
	if(vis[cur]==low[cur]){
		g++;
		while(stk.top()!=cur){
			scc[stk.top()] = g;
			instk[stk.top()]=0;
			stk.pop();
		}
		instk[cur]=0;
		stk.pop();
		scc[cur]=g;
	}
}
vector<vector<int> > gside;
vector<bool> gvis;
void gdfs(int cur){
	gvis[cur]=1;
	for(auto i : gside[cur]){
		if(!gvis[i]) gdfs(i);
	}
	ord.push_back(cur);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int m;cin>>m;
	int q;cin>>q;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	bitset<50001> reach[g+1];
	for(int i=1;i<=g;i++) {
		reach[i].reset();
		reach[i].set(i);
	}
	gside.resize(g+1);	
	for(int i=1;i<=n;i++){
		for(auto v : side[i]){
			gside[scc[i]].push_back(scc[v]);	
		}
	}
	gvis.resize(g+1,0);	
	for(int i=1;i<=g;i++){
		if(!gvis[i]) gdfs(i);
	}
	for(int i=0;i<g;i++){
		for(auto v : gside[ord[i]]){
			reach[ord[i]]|=reach[v];
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		if(reach[scc[a]][scc[b]]) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

