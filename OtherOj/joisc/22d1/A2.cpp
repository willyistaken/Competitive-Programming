#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 120005;
int p[N][20];
vector<int> side[N];
vector<pair<int,int> > qu;
pair<int,int> dep[N];
int n;
int t;
bool vis[N];
int dtime[N];
int t2;
void dfs(int cur){
	dep[cur].first=++t;
	for(auto i : side[cur])	{
		if(p[i][0]) continue;
		p[i][0]=cur;
		dfs(i);
	}
	dep[cur].second=++t;
}
vector<int> fe[N];

bool isanc(int a,int b){
	return (dep[a].first<dep[b].first && dep[a].second>dep[b].second);
}

int lca(int a,int b){
	if(isanc(a,b)) return a;
	if(isanc(b,a)) return b;
	for(int j=19;j>=0;j--){
		if(!isanc(p[b][j],a)) b = p[b][j];
	}
	return p[b][0];
}
vector<int> to[N];
vector<int> from[N];
bool inpath(int a,int b,int u){
	int c = lca(a,b);
	if(a==u || b==u || c==u) return 1;
	if((isanc(u,b)||isanc(u,a)) && isanc(c,u)) return 1;
	return 0;
}

void builtdep(int cur){
	vis[cur]=1;
	for(auto i : fe[cur]){
		if(!vis[i]) builtdep(i);
	}
	dtime[cur]=++t2;
}

void solve(){
	cin>>n;
	//clean up
	for(int i=1;i<=n;i++){
		side[i].clear();
		fe[i].clear();
		for(int j=0;j<20;j++) p[i][j]=0;
		qu.clear();
		dep[i] = {0,0};
		t = 0 ;
		t2=0;
		vis[i]=0;
		dtime[i]=0;
		to[i].clear();
		from[i].clear();
	}
	// built tree
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	for(int j=0;j<20;j++) p[1][j]=1;
	dfs(1);

	int m;
	cin>>m;
	qu.resize(m+1);
	for(int i=1;i<=m;i++) cin>>qu[i].first>>qu[i].second;
	for(int i=1;i<=m;i++){
		to[qu[i].first].push_back(i);
		from[qu[i].second].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int a = qu[i].first;
		int b = qu[i].second;
		while(a!=b){
			if(isanc(b,a)) swap(a,b);
			for(auto k : to[b]){
				fe[k].push_back(i);
			}
			for(auto k : from[b]){
				fe[i].push_back(k);
			}
			b = p[b][0];
		}
			for(auto k : to[b]){
				fe[k].push_back(i);
			}
			for(auto k : from[b]){
				fe[i].push_back(k);
			}
	}

	for(int i=1;i<=m;i++){
		if(!vis[i]) builtdep(i);
	}
	for(int i=1;i<=m;i++){
		for(auto e : fe[i]){
			if(dtime[e]>dtime[i]){
				cout<<"No\n";
				return ;
			}
		}
	}
	cout<<"Yes\n";
	return ;
		
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	while(q--){
		solve();
	}

	return 0;
}

