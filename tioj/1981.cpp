#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){
	int ans = 0; char c = RC(); bool minus = false;
	while((c < '0' or c > '9') and c != '-' and c != EOF) c = RC();
	if(c == '-') minus = true, c = RC();
	while(c >= '0' and c <= '9') ans = ans * 10 + (c ^ '0'), c = RC();
	return minus ? -ans : ans;
}
const int MAXN = 1e6+5;
int scc[MAXN];
vector<int> side[MAXN];
int vis[MAXN],low[MAXN],t;
stack<int> stk;bitset<MAXN> instk;

void dfs(int r){
	vis[r] = low[r] = ++t;
	instk[r]=1;
	stk.push(r);
	for(auto i : side[r]){
		if(!vis[i]){
			dfs(i);
		}
		if(instk[i]){
			low[r] = min(low[i],low[r]);
		}
	}
	if(vis[r]==low[r]){
		while(stk.top()!=r){
			scc[stk.top()]=r;
			instk[stk.top()]=0;
			stk.pop();
		}
		instk[r]=0;
		scc[r]=r;
		stk.pop();
	}
}
queue<int> seq;
void dfs2(int r,vector<vector<int> > &rdag){
	instk[r]=1;
	for(auto i : rdag[r]){
		if(!instk[i]) dfs2(i,rdag);
	}
	seq.push(r);
}

int main(){
	int n,m;n = R();m = R();
	for(int i=0;i<m;i++){
		int a,b;a = R();b = R();
		side[a].push_back(b);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}
	memset(low,0,sizeof(low));
	for(int i=0;i<n;i++) low[scc[i]]++;
	vector<vector<int> > rdagside(n);
	vector<vector<int> > dagside(n);
	memset(vis,0,sizeof(vis));
	
	for(int i=0;i<n;i++){
		for(auto j:side[i]){
			if(scc[j]!=scc[i]){
				dagside[scc[i]].push_back(scc[j]);
				vis[scc[j]]++;
			}
		}
		if(scc[i]!=i) vis[i]=1;
	}
	
	instk.reset();
	memset(scc,0,sizeof(scc));
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs2(i,dagside);
	}
	int ans=1;
	while(seq.size()){
		int te = seq.front();
		seq.pop();
		int maxn = 0;
		for(auto i : dagside[te]){
			maxn = max(maxn,scc[i]);
		}
		scc[te] = maxn+low[te];
		ans = max(ans,scc[te]);
	}
	cout<<ans<<"\n";

	return 0;
}
