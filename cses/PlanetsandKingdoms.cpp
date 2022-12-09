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
	SCC graph;
	graph.init(n);
	for(;m;m--){
		int a,b;cin>>a>>b;
		a--;b--;
		graph.add_edge(a,b);
	}
	vector<int> g = graph.get();
	cout<<graph.gt<<"\n";
	for(auto i : g){
		cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}
