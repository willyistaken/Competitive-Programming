#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct MCMF{
	struct e{
		int to;
		int rev;
		ll cap;
		ll w;
	};
	vector<vector<e>> side;
	vector<int> next;
	vector<ll>  dis;
	vector<bool> vis;
	ll result = 0;
	MCMF(int n){
		side.resize(n);
		next.resize(n);
		dis.resize(n);
		vis.resize(n);
	}
	
	void add_edge(int a,int b,int cap,int cost){
		side[a].push_back({b,(int)side[b].size(),cap,cost});
		side[b].push_back({a,(int)side[a].size()-1,0,-cost});
	}
	
	bool spfa(int s,int t){
		fill(dis.begin(),dis.end(),1e18);
		queue<int> q;
		q.push(s);
		dis[s]=0;
		while(q.size()){
			int cur= q.front();
			q.pop();	
			for(auto e : side[cur]){
				if(e.cap<=0) continue;	
				if(dis[cur]+e.w<dis[e.to]){
					dis[e.to] = dis[cur]+e.w;
					q.push(e.to);
				}
			}
		}
		return (dis[t]<5e17);
	}
	
	ll dfs(int v,int t,ll flow){
		vis[v]=1;	
		if(v==t) return flow;
		for(;next[v]<side[v].size();next[v]++){
			auto &e = side[v][next[v]];
			if(e.cap>0 && dis[e.to]==dis[v]+e.w && !vis[e.to]){
				ll x = dfs(e.to,t,min(e.cap,flow));	
				if(x>0){
					e.cap-=x; 
					side[e.to][e.rev].cap+=x;
					result+= 1LL*x*e.w;		
					return x;
				}
			}
		}
		return -1;
	}
	ll get(int s,int t){
		result = 0;
		ll f = 0;
		ll maxflow = 0;
		while(spfa(s,t)){
			fill(next.begin(),next.end(),0);
			fill(vis.begin(),vis.end(),0);
			while((f=dfs(s,t,1e18))>0){
				maxflow+=f;		
			}
		}
		return maxflow;
	}
};






int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	MCMF graph(2*n+2);
	for(int i=1;i<=n;i++){
		for(int j=n+1;j<=2*n;j++){
			int c;cin>>c;
			graph.add_edge(i,j,1,c);
		}
	}
	for(int i=1;i<=n;i++){
		graph.add_edge(0,i,1,0);
		graph.add_edge(i+n,2*n+1,1,0);
	}
	graph.get(0,2*n+1);
	cout<<graph.result<<"\n";
	for(int i=1;i<=n;i++){
		for(auto &e : graph.side[i]){
			if(e.cap==0) {
				cout<<i<<" "<<e.to-n<<"\n";
				break;
			}
		}
	}
	return 0;
}

