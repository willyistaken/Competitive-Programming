#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int cnt = 0;
const int N = 1e5+5;
bool vis[N];
vector<int> side[N];

void dfs(int cur,int p){
	vis[cur]=1;
	for(auto i : side[cur]){
		if(i==p) continue;
		if(!vis[i]) dfs(i,cur);
		else cnt++;
	}
}
const int MOD = 1e9+7;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i] )dfs(i,i);
	}
	cnt>>=1;
	ll ans = 1;
	for(int i=0;i<cnt;i++) ans = (ans<<1)%MOD;
	cout<<ans<<"\n";
	return 0;
}
