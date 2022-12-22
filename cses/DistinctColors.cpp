#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
bool vis[N];
vector<int> side[N];
int c[N];
int ans[N];
int sz[N];
void find(int v){
	vis[v]=1;
	for(auto i : side[v]){
		if(!vis[i]){
			find(i);
			sz[v]+=sz[i];
		}
	}
	sz[v]++;
}
void dfs(set<int> &s,int v){
	if(v==0) return;
	vis[v]=1;
	int maxsz = 0;int mv = 0;
	for(auto i : side[v]){
		if(!vis[i]){
			if(maxsz<sz[i]){
				mv = i;
				maxsz = sz[i];
			}
		}
	}
	dfs(s,mv);
	for(auto i : side[v]){
		if(!vis[i]){
			if(i!=mv){
				set<int> ts;
				ts.clear();
				dfs(ts,i);
				for(auto g : ts) s.insert(g);
			}
		}
	}
	s.insert(c[v]);
	ans[v] = s.size();
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];	
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	set<int> s;		
	find(1);
	fill(vis,vis+N,0);
	s.clear();
	dfs(s,1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
