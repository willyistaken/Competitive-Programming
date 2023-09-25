#include<bits/stdc++.h>
using namespace std;
typedef int ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MAXN = 4e6; 
struct edge{
	int to;
	ll cap;
	int rev;
};
vector<edge> side[MAXN];
int level[MAXN];
int nxt[MAXN];
struct DINIC{
	int n;
	void init(int s){
		n = s;
		for(int i=0;i<n;i++) side[i].clear();
	}
	
	void add_edge(int a,int b,ll c){
//		cout<<a<<"->"<<b<<"\n";
		side[a].push_back({b,c,(int)(side[b].size())});
		side[b].push_back({a,0,(int)(side[a].size()-1)});
	}
	
	bool bfs(int s,int t){
		fill(level,level+n,-1);
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
		for(;nxt[v]<side[v].size();nxt[v]++){
			auto& e = side[v][nxt[v]];
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
			fill(nxt,nxt+n,0);
			ll f = 0;
			while((f=dfs(s,t,1e9))>0){
				ans+=f;
			}
		}
		return ans;
	}
} graph;
 
 
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	vector<vector<char>> grid(n,vector<char>(m));
	vector<vector<int> > taken(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		string s;cin>>s;	
		for(int j=0;j<m;j++){
			grid[i][j] = s[j];
		}
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j+2<m;j++){
			if(grid[i][j]=='R' && grid[i][j+1]=='G' && grid[i][j+2]=='W'){
				cnt++;
				taken[i][j]=cnt;
				taken[i][j+1]=cnt;
				taken[i][j+2]=cnt;
			}
		}
	}
	//cout<<cnt<<" ";
	int total = cnt;
	for(int j=0;j<m;j++){
		for(int i=0;i+2<n;i++){
			total+=(grid[i][j]=='R' && grid[i+1][j]=='G' && grid[i+2][j]=='W');
		}
	}
	//cout<<total<<"\n";
	graph.init(total+2)	;
	int ton = cnt;
	for(int j=0;j<m;j++){
		for(int i=0;i+2<n;i++){
			if(grid[i][j]=='R' && grid[i+1][j]=='G' && grid[i+2][j]=='W'){
				ton++;
				if(taken[i][j]) graph.add_edge(taken[i][j],ton,1);
				if(taken[i+1][j]) graph.add_edge(taken[i+1][j],ton,1);
				if(taken[i+2][j]) graph.add_edge(taken[i+2][j],ton,1);
			}
		}
	}	

	for(int i=1;i<=cnt;i++){
		graph.add_edge(0,i,1);
	}
	for(int i=cnt+1;i<=total;i++){
		graph.add_edge(i,total+1,1);
	}
	ll ans = graph.flow(0,total+1);
	cout<<total-ans<<"\n";
	return 0;
}

