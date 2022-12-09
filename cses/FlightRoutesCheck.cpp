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
	int bt = 0;
	vector<int> inback;
	void init(int s){
		n = s;
		side.resize(n);
		inback.resize(n,0);
		vis.resize(n,0);
		group.resize(n,-1);
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
			while(stk.top()!=v){
				group[stk.top()] = v;
				instk[stk.top()]=0;
				stk.pop();
			}
			group[v]=v;
			instk[v]=0;
			stk.pop();
		}
		inback[v]=++bt;
	}
	vector<int> get(){
		for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
		return group;
	}
};



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	SCC graph;
	graph.init(n);
	while(m--){
		int a,b;cin>>a>>b;
		a--;b--;
		graph.add_edge(a,b);
	}
	vector<int> ans = graph.get();
	int b = ans[0];
	for(int i=1;i<n;i++){
		if(ans[i]!=b){
			cout<<"NO\n";
			if(graph.inback[i]<graph.inback[0]) cout<<i+1<<" "<<1<<"\n";
			else cout<<1<<" "<<i+1<<"\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}
