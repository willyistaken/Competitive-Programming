#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int MAXN = 10005;
bitset<MAXN> cover;
bitset<MAXN> vis;
int ans;
vector<int> side[MAXN];	
vector<pair<int,int> > dep;
int father[MAXN];
void dfs(int r,int depth,int from){
	father[r]=from;
	vis[r]=1;
	depth++;
	dep.push_back({depth,r});
	for(auto i : side[r]){
		if(!vis[i]) dfs(i,depth,r);
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n){
		cover.reset();
		vis.reset();
		ans=0;
		dep.clear();
		for(int i=0;i<=n;i++) side[i].clear();
		memset(father,0,sizeof(father));
		for(int i=0;i<n-1;i++){
			int a,b;cin>>a>>b;
			side[a].push_back(b);
			side[b].push_back(a);
		}
		dfs(1,0,1);
		sort(dep.begin(),dep.end(),greater<pair<int,int> >());
		for(int i=0;i<n;i++){
			int node = dep[i].second;
			if(!cover[node]){
				for(auto i : side[father[node]]){
					cover[i]=1;
				}
				ans++;
				//cout<<father[node]<<"\n";
				cover[father[node]]=1;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}
