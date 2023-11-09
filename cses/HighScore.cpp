#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<vector<int> > dfss;
bool mark[2505];

bool vis[2505];
bool dfs(int cur){
	if(mark[cur]) return 1;
	vis[cur] = 1;	
	for(auto i : dfss[cur]){
		if(!vis[i]){
			if(mark[i] || dfs(i)) return 1;
		}
	}
	return 0;
}
bool reach[2505];
vector<vector<pair<int,ll> >> side;

void dfsr(int cur){
	reach[cur]=1;
	for(auto i : side[cur]){
		if(!reach[i.first])	 dfsr(i.first);			
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	side.resize(n);
	dfss.resize(n);
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		a--;b--;
		dfss[b].push_back(a);
		side[a].push_back({b,-c});
	}
	ll dis[n];
	for(int i=0;i<n;i++) dis[i]= 1e18;
	dis[0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(auto p : side[j]){
				dis[p.first] = min(dis[p.first],dis[j]+p.second);
			}
		}
	}
	ll p[n];
	for(int i=0;i<n;i++) p[i] = dis[i];
	for(int j=0;j<n;j++){
		for(auto p : side[j]){
			dis[p.first] = min(dis[p.first],dis[j]+p.second);
		}
	}
	dfsr(0);
	for(int i=0;i<n;i++) if(p[i]>dis[i] && reach[i]) mark[i]  = 1;	
	if(dfs(n-1)) cout<<-1<<"\n";
	else cout<<-dis[n-1]<<"\n";
	return 0;
}
