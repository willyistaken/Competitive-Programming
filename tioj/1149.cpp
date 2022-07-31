#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int nt(int k){
	if(k<=n) return k+n;
	else return k-n;
}
const int MAXN = 35;
int vis[MAXN],low[MAXN],scc[MAXN],t;
bitset<MAXN> instk;
stack<int> stk;
vector<int> side[MAXN];
void reset(){
	memset(vis,0,sizeof(vis));
	memset(low,0,sizeof(low));
	memset(scc,0,sizeof(scc));
	t=0;
	instk.reset();
	while(stk.size()) stk.pop();
	for(int i=0;i<MAXN;i++) side[i].clear();
}

void dfs(int r){
	vis[r]=low[r]=++t;
	stk.push(r);
	instk[r]=1;
	for(auto i : side[r]){
		if(!vis[i]) dfs(i);
		if(instk[i]) low[r]= min(low[r],low[i]);
	}
	if(vis[r]==low[r]){
		while(stk.top()!=r){
			scc[stk.top()]=r;
			instk[stk.top()]=0;
			stk.pop();
		}
		scc[r]=r;
		instk[r]=0;
		stk.pop();
	}
}



int main(){
	// h = true, m = false;
	int testdata;scanf("%d\n",&testdata);
	while(testdata--){
		reset();
		scanf("%d %d\n",&n,&m);
		for(int i=0;i<m;i++){
			char a,b;
			int inda,indb;
			scanf("%c%d %c%d",&a,&inda,&b,&indb);
			char temp;
			scanf("%c",&temp);
			if(inda==indb){
				if(a==b){
					if(a=='m'){
						side[inda].push_back(nt(inda));
					}else{
						side[nt(inda)].push_back(inda);
					}

				}
			}else{
				if(a=='m') inda = nt(inda);
				if(b=='m') indb = nt(indb);
				side[nt(inda)].push_back(indb);
				side[nt(indb)].push_back(inda);
			}
		}
		for(int i=1;i<=2*n;i++){
			if(!vis[i]) dfs(i);
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(scc[i]==scc[nt(i)]) {
				flag=1;
				break;
			}
		}
		if(flag){
			puts("BAD");
		}else{
			puts("GOOD");
		}

	}

	return 0;
}
