#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct SCC{
	vector<vector<int> > side;
	int n;
	vector<int> vis,group,low;
	stack<int> stk;
	vector<bool> instk;int t=0;
	int gt = 0;
	void init(int s){
		n = s;
		side.resize(n);
		vis.resize(n,0);
		group.resize(n,0);
		low.resize(n,0);
		instk.resize(n,0);
	}
	void add_edge(int a,int b){
		side[a].push_back(b);
	}
	void dfs(int v){
		vis[v]=low[v]=++t;
		instk[v]=1;
		stk.push(v);
		for(auto i : side[v]){
			if(!vis[i]) dfs(i);
			if(instk[i]) low[v] = min(low[v],low[i]);
		}
		if(vis[v]==low[v]){
			gt++;
			while(stk.top()!=v){
				group[stk.top()] = gt;
				instk[stk.top()]=0;
				stk.pop();
			}
			group[v]=gt;
			instk[v]=0;
			stk.pop();
		}
	}
	vector<int> get(){
		for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
		return group;
	}
};



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int w[n];
	for(int i=0;i<n;i++) cin>>w[i];
	SCC graph;
	graph.init(n);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		graph.add_edge(a,b);
	}
	vector<int> g = graph.get();	
	int N = *max_element(g.begin(),g.end());
	vector<vector<int> > side(N+1);
	for(int i=0;i<n;i++){
		for(auto j : graph.side[i]){
			side[g[j]].push_back(g[i]);
		}
	}
	ll W[N+1] = {0};
	for(int i=0;i<n;i++) W[g[i]]+=w[i];
	ll dp[N+1] ={0};	
	ll Maxn = 0;
	for(int i=N;i>0;i--){
		for(auto p : side[i]){
			dp[i]= max(dp[i],dp[p]);
		}
		dp[i]+=W[i];
		Maxn = max(Maxn,dp[i]);
	}
	cout<<Maxn<<"\n";
	return 0;
}
