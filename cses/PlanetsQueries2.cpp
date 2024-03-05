#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
int nxt[N][20];
int vis[N];
int cir[N];
int c;
int in[N];
int tree[N];
int dis[N];
int ord[N];
int csz[N];
void dfs(int cur,int t){
	vis[cur]=t;
	if(vis[nxt[cur][0]]==t){
		int k = nxt[cur][0];
		int g = k;
		++c;
		cir[g]=c;
		while(nxt[g][0]!=k){
			ord[nxt[g][0]]=ord[g]+1;
			cir[nxt[g][0]]=c;
			g = nxt[g][0];
		}
		return;
	}
	if(vis[nxt[cur][0]]) return;
	dfs(nxt[cur][0],t);
}

void dfs2(int cur){
	if(cir[nxt[cur][0]]){
		tree[cur]=nxt[cur][0];
		dis[cur] = 1;
		return;
	}
	if(!tree[nxt[cur][0]]) dfs2(nxt[cur][0]);
	tree[cur] = tree[nxt[cur][0]];
	dis[cur] = dis[nxt[cur][0]]+1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;		
	int q;cin>>q;
	for(int i=1;i<=n;i++){
		cin>>nxt[i][0];
		in[nxt[i][0]]++;
	}
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			nxt[i][j] = nxt[nxt[i][j-1]][j-1];
		}
	}
	int t = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			++t;
			dfs(i,t);
		}
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0) dfs2(i);
	}
	for(int i=1;i<=n;i++){
		if(cir[i])	csz[cir[i]]++;
	}
	
	while(q--){
		int u,v;cin>>u>>v;
		if(u==v){
			cout<<0<<"\n";
			continue;
		}
		if(cir[u]==cir[v]){
			if(cir[u]){
				if(ord[u]<=ord[v]) cout<<ord[v]-ord[u]<<"\n";
				else cout<<csz[cir[u]]-(ord[u]-ord[v])<<"\n";
			}else{
				if(tree[u]!=tree[v]){
					cout<<-1<<"\n";
				}else{
					if(dis[u]<=dis[v])	{
						cout<<-1<<"\n";
					}else{
						int k = dis[u]-dis[v];
						for(int j=19;j>=0;j--){
							if((k>>j)&1) u = nxt[u][j];
						}
						if(u==v){
							cout<<k<<"\n";
						}else{
							cout<<-1<<"\n";
						}
					}
				}
			}
		}else{
			if(cir[u] && cir[v]){
				cout<<-1<<"\n";
			}else{
				if(!cir[v]){
					cout<<-1<<"\n";
				}else{
					if(cir[tree[u]]==cir[v]){
						int ans = dis[u];
						u = tree[u];
					    if(ord[u]<=ord[v]) cout<<ans+ord[v]-ord[u]<<"\n";
						else cout<<ans+csz[cir[u]]-(ord[u]-ord[v])<<"\n";
					}else{
						cout<<-1<<"\n";
					}
				}
			}
		}
	}

	return 0;

}
