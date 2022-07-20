#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
vector<pair<int,int> > side[MAXN];
int depth[MAXN];pair<int,int> father[MAXN];
int dsu[MAXN];
void dfs(int r,int from,int w){
	dsu[r]=r;
	depth[r]=depth[from]+1;
	father[r] = ((r==1)?(make_pair(1,0)):(make_pair(from,w)));
	for(auto i : side[r]){
		if(!depth[i.first]) dfs(i.first,r,i.second);
	}
}
int query(int u){
	if(dsu[u]==u) return u;
	dsu[u]=query(dsu[u]);
	return dsu[u];
}
void join(int u,int v){
	dsu[query(u)] =query(v);
	return ;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<n;i++) {
		int a,b,w;cin>>a>>b>>w;
		side[a].push_back({b,w});
		side[b].push_back({a,w});
	}
	dfs(1,0,0);			
	while(q--){
		int u,v;cin>>u>>v;
		u = query(u);v = query(v);
		int sum=0;
		while(u!=v){
			if(depth[u]>=depth[v]){
				sum+=father[u].second;
				join(u,father[u].first);
			}else{
				sum+=father[v].second;
				join(v,father[v].first);
			}
			u = query(u);v = query(v);
		}
		cout<<sum<<"\n";
	}


	return 0;
}
