#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
struct e{
	int w;
	int a;
	int b;
};
const int MAXN = 1e5+5;
vector<pair<int,int>> side[MAXN];
int seq[MAXN],t;
bitset<MAXN> vis;
void dfs(int r,int p){
	vis[r]=1;
	for(auto i : side[r]){
		if(i.second>p){
			if(!vis[i.first]) dfs(i.first,p);
		}
	}
	seq[r]=++t;
	//cout<<r<<"\n";
}
int n,m;
vector<e> edge;
bool check(int p){
	fill(seq,seq+n+1,0);
	t = 0;
	vis.reset();
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i,p);
	}
	for(int i=0;i<m;i++){
		if(edge[i].w>p){
			if(seq[edge[i].a]<seq[edge[i].b]) return 0;
		}
	}
	return 1;
	
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,w;cin>>a>>b>>w;
		edge.push_back({w,a,b});
		side[a].push_back({b,w});
	}
	int l= -1;int r = 1e9;
	while(r-l>1){
		int mid = l+ ((r-l)/2);
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout<<r<<" ";
	check(r);	
	int num=0;
	for(int i=0;i<m;i++){
		if(edge[i].w<=r && seq[edge[i].a]<seq[edge[i].b]){
			num++;	
		}
	}
	cout<<num<<"\n";
	for(int i=0;i<m;i++){
		if(edge[i].w<=r && seq[edge[i].a]<seq[edge[i].b]){
			cout<<i+1<<"\n";
		}
	}
	return 0;
}

