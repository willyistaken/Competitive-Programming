#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int N = 200005;
int w[N];
vector<int> side[N];
vector<int> from[N];
int head[N];
int p[N][19];
int dep[N];
ll dp[N];
void dfs(int cur){
	for(auto v : side[cur]){
		if(v==p[cur][0]) continue;
		p[v][0]=cur;
		dep[v]=dep[cur]+1;
		dfs(v);
	}
}

int dis(int a,int b){
	int oga= a;
	int ogb = b;
	if(dep[a]>dep[b]) swap(a,b);
	for(int l = 18;l>=0;l--){
		if(dep[p[b][l]]>dep[a])	b = p[b][l];
	}
	if(dep[b]!=dep[a]) b = p[b][0];
	if(a==b){
		return abs(dep[oga]-dep[ogb]);
	}
	for(int l=18;l>=0;l--){
		if(p[b][l]!=p[a][l]){
			a = p[a][l];
			b = p[b][l];
		}
	}
	if(a!=b) a=p[a][0];
	return abs(dep[a]-dep[oga])+abs(dep[a]-dep[ogb]);
}

int query(int a){
	if(head[a]==a) return a;
	head[a] = query(head[a]);
	return head[a];
}

void join(int a,int b){
	a = query(a);b = query(b);
	if(a==b) return;
	if(w[a]>w[b]) swap(a,b);
	head[a] =b;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	p[1][0]=1;
	dep[1]=1;
	dfs(1);
	for(int l=1;l<19;l++){
		for(int i=1;i<=n;i++){
			p[i][l] = p[p[i][l-1]][l-1];
		}
	}
	int order[n];
	for(int i=1;i<=n;i++) {order[i-1]=i;head[i]=i;}
	sort(order,order+n,[&](const int a,const int b){return w[a]<w[b];});
	for(int i=0;i<n;i++){
		int cur = order[i];
		for(auto v : side[cur]){
			if(w[v]>w[cur]) continue;
			int g = query(v);
			from[g].push_back(cur);
			join(g,cur);
		}
	}
	sort(order,order+n,[&](const int a,const int b){return w[a]>w[b];});
	ll maxn = 0;
	for(int i=1;i<n;i++){
		int cur = order[i];
		for(auto v : from[cur]){
			dp[cur] = max(dp[v]+dis(v,cur),dp[cur]);
		}
		maxn = max(dp[cur],maxn);
	}
	cout<<maxn<<"\n";
	return 0;
}
