#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
vector<int> side[N];
int f[N][25];
int dep[N];
void sdp(int v,int p){
	dep[v] = dep[p]+1;
	f[v][0] = p;
	for(auto i : side[v]){
		if(!dep[i]) sdp(i,v);
	}
}

int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	for(int i=24;i>=0;i--){
		if(dep[f[b][i]]>=dep[a]) b= f[b][i];
	}
	if(a==b) return a;
	for(int i=24;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a = f[a][i];
			b= f[b][i];
		}
	}
	return f[a][0];
}
int cnt[N];
bool vis[N];
void dfs(int v){
	vis[v]=1;
	for(auto i : side[v]){
		if(!vis[i]){
			dfs(i);
			cnt[v]+=cnt[i];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	sdp(1,0);
	fill(f[1],f[1]+25,1);
	for(int j=1;j<25;j++){
		for(int i=2;i<=n;i++){
			f[i][j] = f[f[i][j-1]][j-1];
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		if(dep[a]>dep[b]) swap(a,b);
		int l = lca(a,b);
		cnt[l]--;
		if(l!=1) cnt[f[l][0]]--;
		cnt[a]++;
		cnt[b]++;
	}
	dfs(1);
	for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
	cout<<"\n";
	return 0;
}

