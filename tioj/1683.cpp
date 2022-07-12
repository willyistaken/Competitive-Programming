#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int MAXN = 10005;
int scc[MAXN];
vector<int> side[MAXN];
int vis[MAXN],low[MAXN];
bitset<MAXN> instack;
int t;
stack<int> stk;
void ret(){
	memset(scc,0,sizeof(scc));
	for(int i=0;i<MAXN;i++) side[i].clear();
	memset(vis,0,sizeof(vis));
	memset(low,0,sizeof(low));
	instack.reset();
	while(stk.size()) stk.pop();
	t=0;
}
void dfs(int r){
	vis[r]=low[r]=++t;
	stk.push(r);instack[r]=1;
	for(auto i : side[r]){
		if(!vis[i]) dfs(i);
		if(instack[i]) low[r] = min(low[r],low[i]);
	}
	if(low[r]==vis[r]){
		while(stk.top()!=r){
			scc[stk.top()]=r;
			instack[stk.top()]=0;
			stk.pop();
		}
		scc[r]=r;
		stk.pop();
		instack[r]=0;
	}
	return ;
}
void toposort(stack<int> &result,int r,vector<int> compactside[]){
		instack[r]=1;
		for(auto i : compactside[r]){
			if(!instack[i]) toposort(result,i,compactside);
		}
		result.push(r);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int testdata;cin>>testdata;
	while(testdata--){
		cin>>n>>m;
		ret();
		for(int i=0;i<m;i++){
			int a,b;cin>>a>>b;
			side[a].push_back(b);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]) dfs(i);
		}
		vector<int> compactside[n+1];
		vector<int> rcompactside[n+1];
		int w[n+1]={0};
		for(int i=1;i<=n;i++){
			w[scc[i]]+=1;
			for(auto j : side[i]){
				if(scc[j]!=scc[i]){
					compactside[scc[i]].push_back(scc[j]);
					rcompactside[scc[j]].push_back(scc[i]);
				}
			}
		}
		instack.reset();
		stack<int> process;
		for(int i=1;i<=n;i++){
			if(w[i] && !instack[i]) toposort(process,i,compactside);
		}
		int ans=0;
		while(!process.empty()){
			int cur = process.top();
			process.pop();
			int maxn = 0;
			for(auto i : rcompactside[cur]){
				maxn = max(maxn,w[i]);
			}
			w[cur]+=maxn;
			ans = max(ans,w[cur]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
