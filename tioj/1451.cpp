#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int> > side;
vector<vector<int> > rside;
const int MAXN = 100005;
int scc[MAXN];
stack<int> leavingtime;

void dfs1(int v){
	scc[v]=v;
	for(auto i : side[v]){
		if(!scc[i]){
			dfs1(i);
		}
	}
	leavingtime.push(v);
}
bitset<MAXN> vis;
void dfs2(int boss,int v){
	vis[v]=1;	
	scc[v]=boss;
	for(auto i : rside[v]){
		if(!vis[i]){
			dfs2(boss,i);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	side.resize(n+1);
	rside.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		rside[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!scc[i]) dfs1(i);
	}	
	while(!leavingtime.empty()){
		int cur = leavingtime.top();
		leavingtime.pop();
		if(!vis[cur]){
			dfs2(cur,cur);
		}
	}
	int works[n+1]={0};
	for(int i=1;i<=n;i++){
		for(auto g: rside[i]){
			if(scc[g]!=scc[i]){
				works[scc[i]]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!works[scc[i]]) {
			ans+=1;
			works[scc[i]]=1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
