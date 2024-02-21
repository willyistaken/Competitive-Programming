#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

/*
algorithm:
for every directed edge u->v, if a_u -> a_v has to pass through v, then we call u a ending point, find all ending point, and to multistart bfs, and the answer is that +1;

how to find if a_u -> a_v has to pass through v? 
1. a_u or a_v == v
2. v is a cut point (becuase if i get rid of v than a_u can't go to a_v, the graph is not connected) and u is not in the same bi-point connected component as v, 
note 2. is wrong , you need a block cut tree for that;
*/
const int N = 2e5+5;
int BCC[N];
int t;
int low[N];
int vis[N];
vector<int> side[N];
stack<int> stk;
int c;
int iscut[N];
void dfs(int cur,int p){
	vis[cur]=low[cur]=++t;
	stk.push(cur);
	for(auto i : side[cur]){
		if(i==p) continue;
		if(vis[i]){
			low[cur] = min(low[cur],vis[i]);
		}else{
			dfs(i,cur);
			low[cur] = min(low[cur],low[i]);
			if(low[i]>=vis[cur]){
				c++;				
				while(stk.size() && stk.top()!=i){
					BCC[stk.top()]=c;
					stk.pop();
				}
				BCC[stk.top()]=c;
				stk.pop();
				iscut[cur]=1;
			}
		}
	}
}
int a[N];
bool ending[N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(1,0);
	
	for(int u=1;u<=n;u++){
		for(auto v : side[u]){
			if(a[u]==v || a[v]==v){
				ending[u]=1;
			}
			if(iscut[v]==1 && BCC[u]!=BCC[v]){
				
			}
		}
	}
	return 0;
}
