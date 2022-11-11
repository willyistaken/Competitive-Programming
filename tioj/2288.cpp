#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int low[150005],vis[150005];
vector<pair<int,int> > side[150005];
bool cutpoint[150005];
int t;

void dfs(int v){
	low[v]=vis[v]=++t;
	int chcnt = 0;
	for(auto i : side[v]){
		if(!vis[i.first]){
			dfs(i.first);
			chcnt++;
			if(low[i.first]>=vis[v]){
				cutpoint[v]=  1;
			}
			low[v] = min(low[v],low[i.first]);
		}
		low[v] = min(low[v],vis[i.first]);
	}
	if(v==1){
		if(chcnt>1){
			cutpoint[v]=1;
		}else{
			cutpoint[v] = 0;
		}
	}
}




struct edge{
	int a,b,w;
};

vector<edge> e;
int n,m;
void solve(){
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<(cutpoint[i]?(-1):(n-2))<<" ";
	}
	cout<<"\n";
}
struct dsu{
	vector<int> a;
	void init(){
		a.resize(n+1);
		for(int i=0;i<n+1;i++) a[i] = i;
	}
	int query(int p){
		if(a[p]==p) return p;
		a[p] = query(a[p]);
		return a[p];
	}
	void join(int x,int y){
		a[query(x)] = query(y);
	}
} ds;

ll ans(int g){
	ds.init();
	ll ans = 0;
	int cnt = 0;
	for(int i=0;i<m;i++){
		if(e[i].a==g || e[i].b==g) continue;	
		else{
			if(ds.query(e[i].a)!=ds.query(e[i].b)){
				ans+=e[i].w;	
				ds.join(e[i].a,e[i].b);	
				cnt++;
			}
		}
	}
	if(cnt!=n-2){
		return -1;
	}else{
		return ans;
	}
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool hasother=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        int c;
        cin>>c;
        if(c!=1) hasother = 1;
        side[a].push_back({b,c});
        side[b].push_back({a,c});
		e.push_back({a,b,c});
    }
	if(!hasother){
		solve();
		return 0;
	}
	if(n>2500) return 0; 
	sort(e.begin(),e.end(),[](const edge &a,const edge &b){return a.w<b.w;});
	for(int i=1;i<=n;i++){
		cout<<ans(i)<<" ";
	}
	cout<<"\n";
    return 0;
}
