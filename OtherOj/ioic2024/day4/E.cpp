#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
struct edge{
	int u,v,w;
};

struct dinic{
	struct E{int v,c,r,rc;};
	vector<vector<E> > adj;
	vector<int> vis,dis,it; 
	dinic(int n):adj(n),vis(n),dis(n),it(n){}
	void add(int u,int v,int c,int d=0){ 
		adj[u].push_back({v,c,(int)adj[v].size(),c});
		adj[v].push_back({u,d,(int)adj[u].size()-1,d});
	}
	bool bfs(int s,int t){
		fill(begin(dis),end(dis),INT_MAX);
		queue<int> q;
		q.push(s);
		dis[s]=0;
		while(!q.empty()){ 
			int u = q.front();q.pop();
			for(const auto& [v,c,r,rc]:adj[u]){
				if(dis[v]<INT_MAX || rc==0) continue;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
		return dis[t]<INT_MAX;
	}
	int dfs(int u,int t,int cap){
		if(u==t || cap==0) return cap;
		vis[u]=true;
		for(int &i = it[u];i<(int)adj[u].size();i++){
			auto &[v,c,r,rc] = adj[u][i];
			if(dis[u]+1!=dis[v]) continue;
			int tmp= dfs(v,t,min(cap,rc));
			if(tmp>0){
				rc -=tmp;
				adj[v][r].rc+=tmp;
				return tmp;
			}
		}
		return 0;
	}
	ll flow(int s,int t){
		ll ans = 0,tmp;
		while(bfs(s,t)){
			fill(begin(vis),end(vis),0);
			fill(begin(it),end(it),0);
			while((tmp=dfs(s,t,INT_MAX))>0){
				ans+=tmp;
			}
		}
		return ans;
	}
	bool inSCut(int u){return dis[u]<INT_MAX;}
};

vector<edge> result;

vector<edge> ed;

void gomoryhu(int N){
	vector<int> par(N,0);
	for(int i=1;i<N;i++){ 
		dinic din(N);
		for(const auto &[u,v,c]:ed){
			din.add(u,v,c,c);
		}
		result.push_back({i,par[i],din.flow(i,par[i])});
		for(int j=i+1;j<N;++j){
			if(par[j]==par[i] && din.inSCut(j)) par[j]=i;
		}
	}
}

vector<int> dep;

vector<bool> vis;

vector<pair<int,int> > side[505];
vector<pair<int,int> > p;
void dfs(int cur,int P){
	for(auto i : side[cur]){
		if(i.first==P) continue;
		p[i.first] = {cur,i.second};
		dep[i.first] = dep[cur]+1;
		dfs(i.first,cur);
	}
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;	
	ll allsum = 0;
	for(int i=0;i<m;i++){
		int a,b,w;cin>>a>>b>>w;	
		a--;b--;
		allsum+=w;
		ed.push_back({a,b,w});
	}
	gomoryhu(n);
	dep.resize(n,0);
	vis.resize(n,0);
	p.resize(n,{0,0});
	for(auto e : result){
		side[e.u].push_back({e.v,e.w});
		side[e.v].push_back({e.u,e.w});
	}
	dfs(0,-1);
	p[0] = {0,1e9};
	while(q--)	{
		int s,t;cin>>s>>t;
		s--;t--;
		ll maxn = 1e18;
		while(s!=t){
			if(dep[s]>dep[t]) swap(s,t);
			maxn = min(p[t].second,maxn);
			t = p[t].first;
		}
		cout<<allsum-maxn<<"\n";
	}
	return 0;
}
