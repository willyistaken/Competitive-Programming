#include "game.h"
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<bool> > reach;
vector<vector<int> > side;
void dfs(int cur,int k){
	reach[cur][k]=1;
	for(auto i : side[cur]){
		if(!reach[i][k]) dfs(i,k);
	}
}
int K;
int update(int u,int v){
	side[u].push_back(v);
	for(int i=0;i<K;i++){
		if(u==i || reach[u][i]) dfs(v,i);
		if(reach[i][i]) return 1;
	}
	return 0;
}

void init(int n, int k) {
	reach.resize(n);
	side.resize(n);
	for(int i=0;i<n;i++){
		reach[i].resize(k,0);
	}
	K=k;
	for(int i=0;i<k-1;i++){
		update(i,i+1);
	}
}



int add_teleporter(int u, int v) {
  return update(u,v);
}
