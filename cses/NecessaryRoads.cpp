#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
vector<int> side[N];
int bcc[N];
int vis[N];
int low[N];
int t;
int g;
stack<int> stk;
void dfs(int v,int p){
	vis[v]= low[v]=++t;	
	stk.push(v);
	for(auto u : side[v]){
		if(!vis[u]) {
			dfs(u,v);
		}
		if(u!=p){
			low[v] = min(low[v],low[u]);	
		}
	}
	if(vis[v]==low[v]){
		g++;
		while(stk.top()!=v){
			bcc[stk.top()] = g;		
			stk.pop();
		}
		bcc[v] =g;
		stk.pop();
	}
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
	cout<<g-1<<"\n";	
	for(int i=1;i<=n;i++){
		for(auto j : side[i]){
			if(i>j) continue;
			if(bcc[i]!=bcc[j]) cout<<i<<" "<<j<<"\n";
		}
	}
	return 0;
}
