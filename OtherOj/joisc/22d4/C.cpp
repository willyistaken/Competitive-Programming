#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct edge{
	int a,b,w;
};
const int N = 505;
vector<int> tree[N];
vector<pair<int,int> > prefix;
set<int> in;
int P[N];
vector<edge> eg;	
int n,m;
void dfs(int cur,int p){
	for(auto i : tree[cur]){
		int a = eg[i].a;
		int b = eg[i].b;
		if(cur==b) swap(a,b);
		if(b==p) continue;
		P[b] = i;
		dfs(b,cur);
	}
}
int minedge(int cur){
	for(int i=0;i<=n;i++) P[i]=-1;
	int x = eg[cur].a;
	int y = eg[cur].b;
	dfs(x,x);
	if(P[y]==-1) return -1;
	int minn = -1;
	while(y!=x){
		int ny = eg[P[y]].a+eg[P[y]].b-y;
		int w = eg[P[y]].w;
		if(minn==-1 || w<eg[minn].w) minn = P[y];
		y = ny;
	}
	return minn;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		eg.push_back({a,b,c});
	}
	sort(eg.begin(),eg.end(),[](const edge &a,const edge &b){return a.w<b.w;});
	vector<int> L(m,-1),R(m,1e9+5);
	for(int i=0;i<m;i++){
		int cut = minedge(i);
		L[i]=0;
		if(cut>=0){
			int a = eg[cut].a;
			int b = eg[cut].b;
			int k = find(tree[a].begin(),tree[a].end(),cut)-tree[a].begin();
			tree[a].erase(tree[a].begin()+k);
			k = find(tree[b].begin(),tree[b].end(),cut)-tree[b].begin();
			tree[b].erase(tree[b].begin()+k);
			R[cut] = L[i] = ((eg[cut].w+eg[i].w)/2)+1;
		}
		tree[eg[i].a].push_back(i);
		tree[eg[i].b].push_back(i);
	}
	for(int i=0;i<m;i++){
		prefix.push_back({L[i],i});
		prefix.push_back({R[i],i});
	}
	sort(prefix.begin(),prefix.end());
	int q;cin>>q;
	int head = 0;
	while(q--){
		int x;cin>>x;
		while(head<prefix.size() && prefix[head].first<=x){
			if(in.count(prefix[head].second)) in.erase(prefix[head].second);
			else in.insert(prefix[head].second);
			head++;	
		}
	
		ll ans = 0;
		for(auto e : in){
			//cout<<eg[e].a<<" "<<eg[e].b<<" "<<eg[e].w<<"t\n";
			ans+=abs(eg[e].w-x);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
