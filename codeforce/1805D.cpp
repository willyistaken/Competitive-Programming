#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
vector<int> side[N];

bool vis[N];
int disa[N];
int disb[N];
pair<int,int> dfs(int v){
	vis[v]=1;
	pair<int,int> maxn = {0,0};
	for(auto i :side[v]){
		if(!vis[i]) maxn = max(dfs(i),maxn);	
	}
	if(maxn.first==0) return {1,v};
	else return {maxn.first+1,maxn.second};
}

void dfsv(int dis[],int v){
	for(auto i : side[v]){
		if(!dis[i]){
			dis[i] = dis[v]+1;
			dfsv(dis,i);
		}
	}
}



struct DSU{
	int cnt = 0;
	vector<int> pa;
	void init(int n){
		cnt = n;
		pa.resize(n);
		for(int i=0;i<n;i++) pa[i]=i;
	}
	int query(int u){
		if(pa[u]==u) return u;
		pa[u] = query(pa[u]);
		return pa[u];
	}
	void join(int a,int b){
		int ap = query(a);
		int bp = query(b);
		if(ap==bp) return ;
		cnt--;
		pa[ap]=bp;
	}
} dsu;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	int a = dfs(1).second;	
	fill(vis,vis+1+n,0);
	int b = dfs(a).second;
	disa[a]=1;
	dfsv(disa,a);
	disb[b]=1;
	dfsv(disb,b);
	vector<pair<int,int> > dist(n+1,{0,0});
	for(int i=1;i<=n;i++){
		dist[i] = {max(disa[i],disb[i])-1,i};
	}
	sort(dist.begin(),dist.end());
	dsu.init(n+1);
	int ans[n+1];
	int p = n;
	for(int k=n;k>=1;k--){
		while(k==dist[p].first){
			int to;
			if(disa[dist[p].second]==k+1){
				to = a;
			}else{
				to = b;
			}
			dsu.join(dist[p].second,to);
			p--;
		}
		ans[k] = dsu.cnt-1;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}

