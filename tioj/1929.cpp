#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}

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
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;n = R();m = R();
	instack.reset();
	for(int i=0;i<m;i++){
		int a,b;a = R();b= R();
		side[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	printf("%d\n",nowscc);
	for(int i=1;i<=n;i++) printf("%d ",scc[i]);
	puts("");

	return 0;
}
