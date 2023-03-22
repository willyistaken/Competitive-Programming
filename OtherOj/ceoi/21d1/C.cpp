#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1005;
vector<int> side[N];
bool vis[N];

int dis[N];
int further[N];
void dfs(int v,int p){
	dis[v] = dis[p]+1;
	for(auto i : side[v]){
		if(!dis[i]) dfs(i,v);
	}
}
vector<int> ans;
bool h = 0;
void dfs2(int v,int p){
	if(h) return ;
	ans.push_back(v);
	int more2cnt = 0;		
	for(auto i : side[v]){
		if(i!=p){
			dfs2(i,v);
			further[v] = max(further[i],further[v]);
			if(further[i]>2){
				more2cnt++;
			}
		}
	}
	further[v]++;
	if(more2cnt>1){
		cout<<"NO\n";
		h=1;
		return ;
	}
	ans.push_back(v);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int m;cin>>m;	
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	if(m!=n-1){
		cout<<"NO\n";
		return 0;
	}
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	int maxv = 0;
	int maxn = 0;
	for(int i=1;i<=n;i++){
		if(maxn<dis[i]){
			maxn = dis[i];
			maxv = i;
		}
	}
	dfs2(maxv,0);
	ans.push_back(maxv);
	if(h) return 0;
	cout<<"YES\n"<<ans.size()<<"\n";
	for(auto i : ans){
		cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}
