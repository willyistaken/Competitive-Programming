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
		side[b].push_back({a,0,(int)(side[a].size()-1)});
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
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,c;cin>>n>>m>>c;
	vector<int> x(n+1);
	vector<int> w(n+1);
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) cin>>w[i];
	DINIC graph;
	graph.init(n+2+m);
	for(int i=1;i<=n;i++){
		int sw = w[i];
		int tw = 0;
		if(x[i]) swap(sw,tw);
		graph.add_edge(0,i,sw);
		graph.add_edge(i,n+1,tw);
	}
	ll vsum = 0;
	for(int f=n+2;f<m+n+2;f++){
		int y,v,k;cin>>y>>v>>k;	
		vsum+=v;
		for(int i=0;i<k;i++){
			int a;cin>>a;
			if(!y) graph.add_edge(f,a,1e9);
			else graph.add_edge(a,f,1e9);
		}
		int p;cin>>p;
		int cw = v + (p?c:0);
		if(!y) graph.add_edge(0,f,cw);
		else graph.add_edge(f,n+1,cw);
	}
	ll mincut = graph.flow(0,n+1);
	cout<<vsum-mincut<<"\n";
	return 0;
}


