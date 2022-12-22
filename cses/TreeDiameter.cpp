#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;

int dis[N];
vector<int> side[N];
void dfs(int v,int p){
	dis[v]=dis[p]+1;
	for(auto i : side[v]){
		if(!dis[i]) dfs(i,v);
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(1,0);
	int maxv=0;
	int maxd = 0;
	for(int i=1;i<=n;i++){
		if(maxd<dis[i]){
			maxd = dis[i];
			maxv = i;
		}
	}
	fill(dis,dis+n+1,0);
	dfs(maxv,0);
	maxv = 0;
	for(int i=1;i<=n;i++) maxv = max(maxv,dis[i]);
	cout<<maxv-1<<"\n";
	return 0;
}
