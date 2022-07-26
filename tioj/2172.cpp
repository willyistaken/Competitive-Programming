#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5;
int father[MAXN][18];
vector<int> side[MAXN];
int depth[MAXN];
int n,m;
void dfs(int r,int from){
	depth[r] = depth[from]+1;
	father[r][0]=r;
	father[r][1]=from;
	for(auto i : side[r]){
		if(!depth[i]) dfs(i,r);
	}
}

void init(){
	for(int i=2;i<18;i++){
		for(int j=0;j<n;j++){
			if(j==0){
				father[j][i]=j;	
			}else{
				father[j][i] = father[father[j][i-1]][i-1];
			}
		}
	}
}

int lca(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	if(depth[a]>depth[b]){
		int dif = depth[a]-depth[b];
		for(int i=1;i<18;i++){
			if(dif & 1) a = father[a][i];
			dif>>=1;
		}
	}
	if(a==b) return a;
	assert(depth[a]==depth[b]);
	for(int i=17;i>=0;i--){
		if(father[a][i]!=father[b][i]){
			a = father[a][i];
			b = father[b][i];
		}
	}
	return father[a][1];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(0,0);	
	init();
	for(;m;m--){
		int a,b;cin>>a>>b;
		int L = lca(a,b);
		cout<<(depth[a]-depth[L]+depth[b]-depth[L])<<"\n";
	}
	


	return 0;
}
