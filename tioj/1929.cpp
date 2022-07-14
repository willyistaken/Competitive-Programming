#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000010;
vector<int> side[MAXN];
int vis[MAXN],low[MAXN],scc[MAXN],t;
stack<int> stk;bitset<MAXN> instack;int nowscc;
void dfs(int r){
	vis[r]=low[r]=++t;
	stk.push(r);
	instack[r]=1;
	for(auto i : side[r]){
		if(!vis[i]) dfs(i);
		if(instack[i]) low[r] = min(low[i],low[r]);
	}
	if(vis[r]==low[r]){
		nowscc++;
		while(stk.top()!=r){
			scc[stk.top()] = nowscc;
			instack[stk.top()]=0;
			stk.pop();
		}
		scc[r]=nowscc;
		instack[r]=0;
		stk.pop();
	}
	return ;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	instack.reset();
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	cout<<nowscc<<"\n";
	for(int i=1;i<=n;i++) cout<<scc[i]<<" ";
	cout<<"\n";

	return 0;
}
