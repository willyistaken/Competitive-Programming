#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct DINIC{
	struct edge{
		int to;
		ll cap;
		int rev;
	};
	vector<vector<edge> > side;
	vector<int> level;
	vector<int> next;
	int n;
	void init(int s){
		n = s;
		side.resize(n);
		level.resize(n,0);
		next.resize(n,0);
		for(int i=0;i<n;i++) side[i].clear();
	}
	
	void add_edge(int a,int b,ll c){
		side[a].push_back({b,c,(int)(side[b].size())});
		side[b].push_back({a,c,(int)(side[a].size()-1)});
	}
	
	bool bfs(int s,int t){
		fill(level.begin(),level.end(),-1);
		queue<int> q;
		level[s]=0;
		q.push(s);
		while(q.size()){
			int cur = q.front();
			q.pop();
			for(auto e : side[cur]){
				if(e.cap<=0) continue;
				if(level[e.to]<0){
					level[e.to] = level[cur]+1;
					q.push(e.to);
				}
			}
		}
		return (level[t]!=-1);
	}
	
	ll dfs(int v,int t,ll flow){
		if(v==t) return flow;	
		for(;next[v]<side[v].size();next[v]++){
			auto& e = side[v][next[v]];
			if(e.cap<=0 || level[v]+1!=level[e.to]) continue;	
			ll ans = dfs(e.to,t,min(flow,e.cap));
			if(ans>0){
				e.cap-=ans;
				side[e.to][e.rev].cap+=ans;
				return ans;
			}
		}
		return 0;
	}


	ll flow(int s,int t){
		ll ans= 0;
		while(bfs(s,t)){
			fill(next.begin(),next.end(),0);
			ll f = 0;
			while((f=dfs(s,t,1e18))>0){
				ans+=f;
			}
		}
		return ans;
	}
} graph;

vector<bool> vis;

void dfs(int v){
	vis[v]=1;
	for(auto i : graph.side[v]){
		if(i.cap<=0) continue;
		if(!vis[i.to]) dfs(i.to);
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	graph.init(n);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		graph.add_edge(a,b,1);	
	}
	vis.resize(n,0);
	cout<<graph.flow(0,n-1)<<"\n";
	dfs(0);	
	for(int i=0;i<n;i++){
		if(!vis[i]) continue;
		for(auto e : graph.side[i]){
			if(!vis[e.to]){
				cout<<i+1<<' '<<e.to+1<<"\n";
			}
		}
	}
	return 0;
}


