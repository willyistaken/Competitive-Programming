#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;

int low[N];
int dfn[N];
bool cut[N];
int t;
vector<int> g[N];
int d[N];

void dfs(int u,int par){
	low[u] = dfn[u] = ++t;
	int child = 0;
	for(auto v : g[u]){
		if(!dfn[v]){
			child++;
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v]>=dfn[u] && u!=1){
				cut[u]=1;
			}
		}else if(v!=par){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(u==1 && child>=2) cut[1]=1;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;		
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a); 
		d[a]++;
		d[b]++;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		if(d[i]>2 && !cut[i]){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}
