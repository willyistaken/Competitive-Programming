#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
vector<int> side[MAXN];
int p[MAXN][20];
bitset<MAXN> vis;
int depth[MAXN];
void dfs(int r,int from){
	vis[r]=1;
	depth[r]=depth[from]+1;
	p[r][0]=from;
	for(int i=1;i<20;i++){
		p[r][i] = p[p[r][i-1]][i-1];
	}
	for(auto i : side[r]){
		if(!vis[i]){
			dfs(i,r);
		}
	}	
	return ;
}

int LCA(int x,int y){
	if(depth[x]<depth[y]) swap(x,y);
	if(depth[x]>depth[y]){
		int dif = depth[x]-depth[y];
		for(int i=0;i<20;i++){
			if(dif&1) x = p[x][i];
			dif>>=1;
		}
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(p[x][i]!=p[y][i]){
			x = p[x][i];
			y = p[y][i];
		}
	}
	return p[x][0];
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vis.reset();
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	for(int i=0;i<20;i++) p[1][i]=1;	
	dfs(1,0);
	while(q--){
		int s,t,k;cin>>s>>t>>k;
		int lca = LCA(s,t);
		if(k == depth[s]-depth[lca]) cout<<lca<<"\n";
		else{
			if(k>depth[s]-depth[lca]){
				k = (depth[t]-depth[lca])-(k-(depth[s]-depth[lca]));
				if(k<0) {cout<<-1<<"\n";continue;}
				for(int i=0;i<20;i++){
					if(k & 1) t = p[t][i];
					k>>=1;
				}
				cout<<(t)<<"\n";
			}else{
				for(int i=0;i<20;i++){
					if(k & 1) s = p[s][i];
					k>>=1;
				}
				cout<<s<<"\n";
			}
		}
	}


	return 0;
}
