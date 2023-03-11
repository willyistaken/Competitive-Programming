#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define INF 1e16
const int N = 1005; 
int n;

struct node{
	ll v[N][2];
	int sz = 1;
	node(void){
		for(int i=0;i<=1000;i++){
			v[i][0]=INF;
			v[i][1] =INF;
		}
		v[0][0]=0;
	}
	ll w=0;
};


void combine(node &a,node &b){	
	node r;
	r.w = a.w;
	a.sz = a.sz+b.sz;
	for(int i=0;i<=a.sz;i++){
		for(int j=0;j<=i;j++){
			r.v[i][1] = min(r.v[i][1],a.v[j][1]+b.v[i-j][0]);
			r.v[i][0] = min(r.v[i][0],a.v[j][0]+b.v[i-j][1]);
			r.v[i][1] = min(r.v[i][1],a.v[j][1]+b.v[i-j][1]);
			r.v[i][0] = min(r.v[i][0],a.v[j][0]+b.v[i-j][0]);
			if(j!=i) r.v[i][1] = min(r.v[i][1],a.v[j][1]+b.v[i-j-1][0]+b.w);
			if(j!=i) r.v[i][1] = min(r.v[i][1],a.v[j][0]+b.v[i-j-1][1]+a.w);
			if(i-j>=2) r.v[i][1] = min(r.v[i][1],a.v[j][0]+b.v[i-j-2][0]+a.w+b.w);
		}
	}
	for(int i=0;i<=n;i++){
		a.v[i][0] = r.v[i][0];
		a.v[i][1] = r.v[i][1];
	}
}



node dp[N];
vector<int> side[N];
int m;

bool vis[N];
void dfs(int cur,int p){
	vis[cur]=1;
	for(auto i : side[cur]){
		if(!vis[i]){
			dfs(i,cur);
			combine(dp[cur],dp[i]);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;				
	for(int i=1;i<=n;i++) cin>>dp[i].w;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	node ans;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,0);
			combine(ans,dp[i]);
		}
	}
	vector<ll> k(n+1,0);
	for(int i=0;i<=n;i++){
		k[i] = ans.v[i][0];
	}
	for(int i=n-1;i>=0;i--){
		k[i] = min(k[i],k[i+1]);
	}
	int q;cin>>q;
	while(q--){
		int s;cin>>s;
		cout<<upper_bound(k.begin(),k.end(),s)-k.begin()-1<<"\n";
	}
	return 0;
}
