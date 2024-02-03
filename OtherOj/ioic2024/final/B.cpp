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
	bool incut(int u){
		return (level[u]>=0);
	}
};



const int N = 5e4+5;
vector<int> side[N];
int c[N];
int group[N];
int dep[N]; 
int p[N];
int stuff[N][2];
void dfs(int cur,int u){
	for(auto i : side[cur]){
		if(i==u) continue;
		dep[i] = dep[cur]+1;
		p[i]=cur;
		dfs(i,cur);
	}
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dep[1]=0;
	p[1]=0;
	dfs(1,0);
	int g = 0;
	for(int i=1;i<=n;i++){
		if(!stuff[c[i]][dep[i]&1]){
			stuff[c[i]][dep[i]&1]=i;
			group[i] = ++g;
		}else{
			group[i] = group[stuff[c[i]][dep[i]&1]];
		}
	}
	DINIC graph;	
	graph.init(g+2);
	graph.add_edge(0,group[1],1);
	for(int i=2;i<=n;i++){
		int u = p[i];
		if(dep[i]&1){
			graph.add_edge(group[i],g+1,1);
			graph.add_edge(group[u],group[i],1);
		}else{
			graph.add_edge(0,group[i],1);
			graph.add_edge(group[i],group[u],1);
		}
	}
	cout<<n-graph.flow(0,g+1)<<"\n";
	int cnt = 0;	
	for(int i=1;i<=n;i++){
		if(!((graph.incut(group[i]))^(dep[i]&1))) cnt++;
	}
	cout<<cnt;
	for(int i=1;i<=n;i++){
		if(!((graph.incut(group[i]))^(dep[i]&1))) cout<<" "<<i;
	}
	cout<<"\n";
	return 0;
}
