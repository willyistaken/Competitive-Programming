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
	vector<bool> vis;
	int n;
	void init(int s){
		n = s;
		side.resize(n);
		level.resize(n,0);
		next.resize(n,0);
		vis.resize(n);
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
	



} G;




pair<int,int> edge[500][500];
int hoz,ver;
bool arr[500][500];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;		
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<m;j++) arr[i][j]= (s[j]=='1');
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0) continue;
			int k = i+1;
			while(k<n && arr[k][j]==0){
				if(k==i+1) ++ver;
				edge[k][j].first = ver;
				k++;
			}
			k = j+1;
			while(k<m && arr[i][k]==0){
				if(k==j+1) ++hoz;
				edge[i][k].second = hoz;
				k++;
			}
		}
	}
	G.init(hoz+ver+2);
	for(int i=1;i<=ver;i++){
		G.add_edge(0,i,1);
	}
	for(int i=ver+1;i<=hoz+ver;i++){
		G.add_edge(i,hoz+ver+1,1);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]) continue;
			G.add_edge(edge[i][j].first,edge[i][j].second+ver,1);
		}
	}
	int ans = G.flow(0,hoz+ver+1);
	cout<<ans<<"\n";
	return 0;
}
