#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
vector<int> side[N];
int vis[N];
int low[N];
int t;
set<int> s;
void dfs(int v,int p){
	vis[v]= low[v]=++t;	
	int c = 0;
	for(auto u : side[v]){
		if(!vis[u]){
			c++;
			dfs(u,v);
			if(p!=0 && low[u]>=vis[v]){
				s.insert(v);
			}
			low[v] = min(low[u],low[v]);
		}else{
			low[v] = min(low[v],vis[u]);
		}
	}
	if(p==0 && c>1) s.insert(v);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i,0);
	}
	cout<<s.size()<<"\n";
	for(auto i : s) cout<<i<<" ";
	return 0;
}

