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
		bool type=0;
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
		side[b].push_back({a,0,(int)(side[a].size()-1),1});
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
int n,m;
stack<int> stk;
vector<bool> vis;
bool dfs(int v){
	vis[v]= 1;
	stk.push(v);
	if(v==n-1) return 1;
	for(auto& e:graph.side[v]){
		if(e.cap!=0 || vis[e.to] || e.type) continue;
		e.cap=1;
		if(dfs(e.to)) return 1;
		e.cap=0;
	}
	stk.pop();
	vis[v]=0;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	graph.init(n);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		graph.add_edge(a,b,1);
	}
	int k = graph.flow(0,n-1);
	cout<<k<<"\n";
	vis.resize(n);
	for(int i=0;i<k;i++){
		while(stk.size()) stk.pop();
		fill(vis.begin(),vis.end(),0);
		dfs(0);
		cout<<stk.size()<<"\n";	
		vector<int> arr;
		while(stk.size()){
			arr.push_back(stk.top());
			stk.pop();
		}
		for(auto i  = arr.rbegin();i!=arr.rend();++i){
			cout<<*i+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}



