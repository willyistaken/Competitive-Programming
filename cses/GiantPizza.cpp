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

int n,m;

int nt(int a){
	if(a<m) return a+m;
	else return a-m;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	SCC graph;
	cin>>n>>m;
	graph.init(2*m);
	for(int i=0;i<n;i++){
		char ca,cb;
		int na,nb;
		cin>>ca>>na>>cb>>nb;
		na--;nb--;
		if(ca=='+') na = nt(na);
		if(cb=='+') nb = nt(nb);
		graph.add_edge(na,nt(nb));
		graph.add_edge(nb,nt(na));
	}
	vector<int> scc  = graph.get();
	bool check[m] = {0};
	for(int i=0;i<m;i++){
		if(scc[i]==scc[nt(i)]){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
		check[i] = (scc[i]<scc[nt(i)]);
	}
	char a[2] = {'-','+'};
	for(int i=0;i<m;i++) cout<<a[check[i]]<<" ";
	cout<<"\n";
	return 0;
}
