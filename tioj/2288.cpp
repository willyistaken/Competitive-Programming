#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct DSU{
	vector<int> p;
	DSU(int _n=-1){
		p.resize(_n+1);
		for(int i=1;i<=_n;i++) p[i]=i;
	}
	int query(int a){
		assert(a<p.size());
		if(p[a]==a) return a;
		p[a] = query(p[a]);
		return p[a];
	}
	void join(int a,int b){
		a = query(a);b = query(b);
		p[b]=a;
		return;
	}
};
const int N = 150005;
vector<int> side[N];
ll ans[N];
vector<bool> taken;
const int B = 20;
int P[N][B];
pair<int,int> dfn[N];
int T;

void dfs(int cur,int p){
	P[cur][0]=p;
	dfn[cur].first=++T;
	for(int i=0;i<side[cur].size();i++){
		if(side[cur][i]!=p){
			dfs(side[cur][i],cur);
		}
	}
	dfn[cur].second=++T;
}

bool isanc(int a,int b){
	return (dfn[a].first<=dfn[b].first && dfn[a].second>=dfn[b].second);
}

int lca(int a,int b){
	if(isanc(a,b)) return a;
	if(isanc(b,a)) return b;
	for(int j=B-1;j>=0;j--){
		if(!isanc(P[b][j],a)) b = P[b][j];
	}
	return P[b][0];
}
DSU top(N);
vector<DSU> vset(1);
void goup(int a,int b,int w){
	assert(isanc(b,a));
	a = top.query(a);
	while(!isanc(P[a][0],b)){
		int v = P[a][0];
		int c =  lower_bound(side[v].begin(),side[v].end(),a)-side[v].begin()+1;
		int r = lower_bound(side[v].begin(),side[v].end(),P[v][0])-side[v].begin()+1;
		if(vset[v].query(r)!=vset[v].query(c)){
			ans[v]+=w;
			vset[v].join(r,c);
		}
		top.join(P[a][0],a);
		a = top.query(a);
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	taken.resize(m,0);
	vector<tuple<int,int,int> > eset;			
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		eset.emplace_back(u,v,w);
	}
	sort(eset.begin(),eset.end(),[](tuple<int,int,int> &a,tuple<int,int,int> &b){return get<2>(a)<get<2>(b);});
	DSU all(n);
	ll W = 0;
	int temp = 0;
	for(auto &[u,v,we] : eset){
		if(all.query(u)!=all.query(v)){
			W+=we;
			all.join(u,v);
			taken[temp]=1;
			side[u].push_back(v);
			side[v].push_back(u);
			ans[u]-=we;
			ans[v]-=we;
		}
		temp++;
	}
	for(int i=1;i<=n;i++) ans[i]+=W;
	
	for(int i=1;i<=n;i++){
		vset.emplace_back(side[i].size());
		sort(side[i].begin(),side[i].end());
	}
	dfs(1,1);
	for(int j=1;j<B;j++){
		for(int i=1;i<=n;i++){
			P[i][j] = P[P[i][j-1]][j-1];
		}
	}
	for(int i=0;i<m;i++){
		if(taken[i]) continue;
		auto &[u,v,w] = eset[i];
		if(isanc(u,v)){
			goup(v,u,w);
		}else if(isanc(v,u)){
			goup(u,v,w);
		}else{
			int c = lca(u,v);
			goup(u,c,w);
			goup(v,c,w);
			for(int j=B-1;j>=0;j--){
				if(!isanc(P[u][j],c)) u = P[u][j];
				if(!isanc(P[v][j],c)) v = P[v][j];
			}
			int a = lower_bound(side[c].begin(),side[c].end(),u)-side[c].begin()+1;
			int b = lower_bound(side[c].begin(),side[c].end(),v)-side[c].begin()+1;
			if(vset[c].query(a)!=vset[c].query(b)){
				vset[c].join(a,b);
				ans[c]+=w;
			}
		}
	}
	for(int i=1;i<=n;i++){
		bool k = 1;
		for(int j=1;j<side[i].size();j++){
			k&=(vset[i].query(j)==vset[i].query(j+1));
		}
		if(!k) cout<<-1<<" ";
		else  cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
