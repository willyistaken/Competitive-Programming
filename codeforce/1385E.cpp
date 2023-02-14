#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
vector<int> side[N];
bool vis[N];
int num[N];
struct edge{
	bool type;	
	int x;
	int y;
};
int seq = 0;
void dfs(int cur){
	vis[cur]=1;
	for(auto i : side[cur]){
		if(!vis[i]) dfs(i);
	}
	num[cur]=++seq;
}

void solve(){
	int n,m;cin>>n>>m;
	seq=0;
	for(int i=1;i<=n;i++) {
		side[i].clear();
		vis[i]=0;
		num[i]=0;
	}
	edge s[m];
	for(int i=0;i<m;i++){
		int t,a,b;cin>>t>>a>>b;
		s[i] = {(bool)t,a,b};	
		if(t) side[a].push_back(b);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);	
	for(auto k : s){
		if(!k.type) continue;
		if(num[k.x]<num[k.y]){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	for(auto k : s){
		if(num[k.x]<num[k.y]) swap(k.x,k.y);
		cout<<k.x<<" "<<k.y<<"\n";
	}
	return ;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
