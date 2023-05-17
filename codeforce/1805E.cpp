#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
bool vis[N];
vector<int> side[N];
int c[N];
int ans1[N];
int ans2[N];
int sz[N];
int n;
int bigcnt[N];
int p[N];
void find(int v){
	vis[v]=1;
	for(auto i : side[v]){
		if(!vis[i]){
			find(i);
			sz[v]+=sz[i];
		}else{
			p[v] = i;
		}
	}
	sz[v]++;
}

struct addmax{
	map<int,int> cnt;
	int maxn = 0;
	void clear(){
		cnt.clear();
		maxn = 0;
	}
	void insert(pair<int,int> k){
		cnt[k.first]+=k.second;
		if(cnt[k.first]>1) maxn = max(maxn,k.first);
	}
};

struct minusmax{
	map<int,int> cnt;
	int maxstuff = n;
	void clear(){
		cnt.clear();
		maxstuff= n;
	}
	void insert(pair<int,int> k){
		cnt[k.first]+=k.second;
		while((cnt.count(maxstuff) && cnt[maxstuff]>=bigcnt[maxstuff]-1)||(bigcnt[maxstuff]<=1)) maxstuff--;
	}
};


void dfs(addmax &s,int v){
	if(v==0) return;
	vis[v]=1;
	int maxsz = 0;int mv = 0;
	for(auto i : side[v]){
		if(!vis[i]){
			if(maxsz<sz[i]){
				mv = i;
				maxsz = sz[i];
			}
		}
	}
	dfs(s,mv);
	for(auto i : side[v]){
		if(!vis[i]){
			if(i!=mv){
				addmax ts;
				ts.clear();
				dfs(ts,i);
				for(auto g : ts.cnt) s.insert(g);
			}
		}
	}
	s.insert({c[v],1});
	ans1[v] = s.maxn;
}

void dfs2(minusmax &s,int v){
	if(v==0) return;
	vis[v]=1;
	int maxsz = 0;int mv = 0;
	for(auto i : side[v]){
		if(!vis[i]){
			if(maxsz<sz[i]){
				mv = i;
				maxsz = sz[i];
			}
		}
	}
	dfs2(s,mv);
	for(auto i : side[v]){
		if(!vis[i]){
			if(i!=mv){
				minusmax ts;
				ts.clear();
				dfs2(ts,i);
				s.maxstuff = min(s.maxstuff,ts.maxstuff);
				for(auto g : ts.cnt) s.insert(g);
			}
		}
	}
	s.insert({c[v],1});
	ans2[v] = s.maxstuff;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	vector<int> d;
	vector<pair<int,int> > edge(n-1);
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		if(a>b) swap(a,b);
		side[a].push_back(b);
		side[b].push_back(a);
		edge[i] = {a,b};
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		d.push_back(c[i]);
	}
	bigcnt[0]=INT_MAX;
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=1;i<=n;i++) {
		c[i] = lower_bound(d.begin(),d.end(),c[i])-d.begin()+1;
		bigcnt[c[i]]++;
	}
	addmax s;
	find(1);
	fill(vis,vis+N,0);
	s.clear();
	dfs(s,1);
	minusmax t;
	fill(vis,vis+N,0);
	t.clear();
	dfs2(t,1);
	for(int i=0;i<n-1;i++){
		int v = edge[i].first;
		if(p[edge[i].first]!=edge[i].second){
			v = edge[i]	.second;
		}
		int ans = max(ans1[v],ans2[v]);
		if(ans==0) cout<<0<<" ";
		else cout<<d[ans-1]<<" ";
	}
	cout<<"\n";
	return 0;
}

