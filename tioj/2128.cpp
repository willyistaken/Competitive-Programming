#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct dinic{
	struct e{
		int to;
		ll cap;
		int rev;
	};
	vector<vector<e> > graph;				
	vector<int> level;
	vector<int> next;
	void init(int n){
		graph.resize(n);
		level.resize(n,0);
		next.resize(n,0);	
	}
	void add_edge(int a,int b,ll c){
		graph[a].push_back({b,c,(int)graph[b].size()});
		graph[b].push_back({a,0,(int)graph[a].size() - 1});
	}
	bool bfs(int s,int t){
		queue<int> q;
		fill(level.begin(),level.end(),0);
		fill(next.begin(),next.end(),0);
		q.push(s);
		level[s]=1;
		while(q.size()){
			int cur = q.front();
			q.pop();
			if(cur==t){
				return 1;
			}
			for(auto i : graph[cur]){
				if(i.cap<=0) continue;
				if(!level[i.to]){
					level[i.to] = level[cur]+1;
					q.push(i.to);
				}
			}
		}
		return 0;
	}
	ll dfs(int cur,int t,ll flow){
		if(cur==t)	return flow;
		for(;next[cur]<graph[cur].size();next[cur]++){
			auto &edge = graph[cur][next[cur]];		
			if(!(edge.cap>0 && level[edge.to]==level[cur]+1)) continue;
			ll s  = dfs(edge.to,t,min(flow,edge.cap));
			if(s>0){
				edge.cap-=s;
				graph[edge.to][edge.rev].cap+=s;
				return s;
			}
		}
		return -1;
	}
	ll maxflow(int s,int t){
		ll ans = 0;
		ll f =0;
		while(bfs(s,t)){
			if((f = dfs(s,t,1e18))>0){
				ans+=f;
			}
		}
		return ans;
	}
};


void solve(){
	int n,m;cin>>n>>m;
	dinic D;
	D.init(n+m+2);
	ll sum = 0;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		D.add_edge(m+i,m+n+1,a);
	}
	for(int i=1;i<=m;i++){
		int ni;cin>>ni;
		int pi;cin>>pi;
		D.add_edge(0,i,pi);
		sum+=pi;
		for(int k=0;k<ni;k++){
			int a;cin>>a;
			D.add_edge(i,m+a,1e16);
		}
	}
	cout<<sum-D.maxflow(0,n+m+1)<<"\n";
	queue<int> q;		
	int vis[n+m+2] = {0};
	vis[0]=1;
	q.push(0);
	while(q.size()){
		int cur = q.front();
		q.pop();
		for(auto e : D.graph[cur]){
			if(e.cap<=0) continue;
			if(vis[e.to]) continue;
			vis[e.to]=1;
			q.push(e.to);
		}
	}
	vector<int> ans;
	for(int i=m+1;i<=m+n;i++){
		if(vis[i]) ans.push_back(i-m);
	}
	cout<<ans.size()<<"\n";
	for(auto i : ans) cout<<i<<" ";
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
