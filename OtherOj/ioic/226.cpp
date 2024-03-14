#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct DINIC{
	struct edge{
		int v;
		int rev;	
		int cap;
		edge(int a,int b,int c):v(a),rev(b),cap(c){}
	};
	vector<vector<edge> > side;
	vector<int> level;
	vector<int> next;
	int n;
	DINIC(int _n){
		n = _n;
		side.resize(n);
		level.resize(n,0);
		next.resize(n,0);
	}
	void add_edge(int u,int v,int c){
		side[u].emplace_back(v,(int)side[v].size(),c);
		side[v].emplace_back(u,(int)side[u].size()-1,c);
	}
	bool bfs(int s,int t){
		fill(level.begin(),level.end(),0);
		queue<int> q;
		level[s]=1;
		q.push(s);
		while(q.size()){
			int cur = q.front();
			q.pop();
			for(auto e : side[cur]){
				if(e.cap<=0) continue;
				if(level[e.v]==0){
					level[e.v]=level[cur]+1;
					q.push(e.v);
				}
			}
		}
		return (level[t]);
	}
	int dfs(int u,int t,int neck){
		if(u==t){
			return neck;
		}
		for(;next[u]<side[u].size();next[u]++){
			auto &e = side[u][next[u]];
			if(e.cap<=0 || level[u]+1!=level[e.v]) continue;
			ll ans = dfs(e.v,t,min(neck,e.cap));
			if(ans>0){
				e.cap-=ans;
				side[e.v][e.rev].cap+=ans;
				return ans;
			}
		}
		return 0;
	}
	int flow(int s,int t){
		int ans = 0;
		while(bfs(s,t)){
			fill(next.begin(),next.end(),0);
			ll f = 0;
			while((f=dfs(s,t,1e9))>0){
				ans+=f;
			}
		}
		return ans;
	}
};
struct E{
	int u,v,w;
	E(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<E> es;	
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		u--;v--;
		es.emplace_back(u,v,w);
	}
	sort(es.begin(),es.end(),[](const E &a,const E &b){return a.w<b.w;});
	int q;cin>>q;
	while(q--){
		int u,v,w;cin>>u>>v>>w;			
		u--;v--;
		int ans = 0;
		{
			int l = -1;
			int r = m;
			while(r-l>1){
				int mid = (l+r)/2;
				if(es[mid].w<w) l = mid;
				else r = mid;
			}
			DINIC graph(n);
			for(int i=0;i<=l;i++){
				graph.add_edge(es[i].u,es[i].v,1);
			}
			ans+=graph.flow(u,v);
		}

		{
			int l = -1;
			int r = m;
			while(r-l>1){
				int mid = (l+r)/2;
				if(es[mid].w>w) r = mid;
				else l = mid;
			}
			DINIC graph(n);
			for(int i=m-1;i>=r;i--){
				graph.add_edge(es[i].u,es[i].v,1);
			}
			ans+=graph.flow(u,v);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
