#pragma GCC target("popcnt")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> ord;
vector<int> side[50000];
bool vis[50000];
void dfs(int cur){
	vis[cur]=1;
	for(auto i : side[cur]){
		if(!vis[i]) dfs(i);
	}
	ord.push_back(cur);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int m;cin>>m;
	bitset<50000> reach[n];
	for(int i=0;i<n;i++){
		reach[i].reset();
		reach[i][i]=1;
	}
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		side[a].push_back(b);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}
	for(int i=0;i<n;i++){
		for(auto v : side[ord[i]]){
			reach[ord[i]]|=reach[v];
		}
	}
	for(int i=0;i<n;i++){
		cout<<reach[i].count()<<" ";
	}
	cout<<"\n";
	return 0;
}
