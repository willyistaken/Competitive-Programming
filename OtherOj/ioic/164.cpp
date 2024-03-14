#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
vector<pair<int,int> > d;
vector<int> pos[2];


struct segment_sat{
	int n;	
	vector<vector<int> > side;
	vector<int> mp;
	vector<int> vis;
	vector<int> low;
	vector<bool> instk;
	stack<int> stk;
	vector<int> scc;
	int scc_cnt;
	int t=0;
	void build(int l,int r,int ind){
		if(r==l){
			mp[l]=ind;
			return;
		}
		int mid = (l+r)/2;
		side[ind].push_back(2*ind);
		side[ind].push_back(2*ind+1);
		build(l,mid,2*ind);
		build(mid+1,r,2*ind+1);
	}
	void init(int _n){
		n = _n;	
		side.resize(4*n);
		mp.resize(n,0);
		vis.resize(4*n,0);
		low.resize(4*n,0);
		instk.resize(4*n,0);
		scc.resize(4*n,0);
		t=0;
		scc_cnt=0;
		build(0,n-1,1);
	}
	void range_add(int x,int l,int r,int L,int R,int ind){
		if(l==L && r==R){
			side[mp[x]].push_back(ind);
			return;
		}
		int M = (L+R)/2;
		if(r<=M) range_add(x,l,r,L,M,2*ind);
		else if(l>M) range_add(x,l,r,M+1,R,2*ind+1);
		else{
			range_add(x,l,M,L,M,2*ind);
			range_add(x,M+1,r,M+1,R,2*ind+1);
		}
	}
	void add_edges(int x,int l,int r){
		if(l>r) return;
		range_add(x,l,r,0,n-1,1);
	}

	void dfs(int cur){
		low[cur]=vis[cur]=++t;
		stk.push(cur);
		instk[cur]=1;
		for(auto i : side[cur]){
			if(!vis[i]) dfs(i);
			if(instk[i]) low[cur] = min(low[i],low[cur]);
		}
		if(low[cur]==vis[cur]){
			scc_cnt++;			
			while(stk.top()!=cur){
				scc[stk.top()]=scc_cnt;
				instk[stk.top()]=0;
				stk.pop();
			}
			scc[cur]=scc_cnt;
			instk[cur]=0;
			stk.pop();
		}
	}
	void build_scc(){
		for(int i=0;i<4*n;i++){
			if(!vis[i]) dfs(i);
		}
	}
	int query_scc(int x){
		return scc[mp[x]];
	}
	void print_scc(int l,int r,int ind){
		cout<<l<<" "<<r<<" "<<ind<<":"<<scc[ind]<<"\n";
		if(l==r) return;
		int m=(l+r)/2;
		print_scc(l,m,2*ind);
		print_scc(m+1,r,2*ind+1);
	}
};
int n;
bool ok(int k){
	segment_sat G;	
	G.init((int)d.size());
	for(int i=0;i<n;i++){
		for(int f=0;f<2;f++){
			int p = pos[f][i];
			int q = pos[!f][i];
			int l = lower_bound(d.begin(),d.end(),make_pair(p-k+1,(int)-1))-d.begin();
			int r = upper_bound(d.begin(),d.end(),make_pair(p+k-1,(int)1e9))-d.begin()-1;
			int x = lower_bound(d.begin(),d.end(),make_pair(q,i))-d.begin();
			int m = lower_bound(d.begin(),d.end(),make_pair(p,i))-d.begin();
			if(p==q){
				x+=f;	
				m+=!f;
			}
			G.add_edges(x,m+1,r);
			G.add_edges(x,l,m-1);
		}
	}
	G.build_scc();
	
	
	for(int i=0;i<n;i++)	{
		int p = pos[0][i];
		int q = pos[1][i];
		p = lower_bound(d.begin(),d.end(),make_pair(p,i))-d.begin();
		q = lower_bound(d.begin(),d.end(),make_pair(q,i))-d.begin();
		if(p==q){
			q++;
		}
		if(G.query_scc(p)==G.query_scc(q)) return 0;
	}
	return 1;
}


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	pos[0].resize(n);
	pos[1].resize(n);
	for(int i=0;i<n;i++){
		cin>>pos[0][i]>>pos[1][i];
		d.push_back({pos[0][i],i});
		d.push_back({pos[1][i],i});
	}
	sort(d.begin(),d.end());
	int l = 0;
	int r = 1e9+5;
	while(r-l>1){
		int mid = (l+r)/2;
		if(ok(mid)) l = mid;
		else r = mid;
	}
	cout<<l<<"\n";
	return 0;
}
