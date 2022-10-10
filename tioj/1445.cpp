#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

int n,m;
struct dsu{
		vector<int> arr;
		void init(int n){
			arr.resize(n+1);
			for(int i=0;i<=n;i++) arr[i]=i;
		}
		int query(int a){
			if(arr[a]==a) return a;
			arr[a] = query(arr[a]);
			return arr[a];
		}
		void join(int a,int b){
			arr[query(a)] = query(b);
			return ;
		}
};
vector<pair<int,ll> > side[1005];
struct e{
	int to;
	int from;
	ll w;
};

pair<int,ll> father[1005][10];
int depth[1005];
void dfs(int r,int p){
	depth[r] = depth[p]+1;
	for(auto i : side[r]){
		if(i.first==p){
			father[r][0] = {p,i.second};
		}else{
			dfs(i.first,r);
		}
	}
}

void buildlca(){
	for(int j=1;j<10;j++){
		for(int i=1;i<=n;i++){
			father[i][j].first = father[father[i][j-1].first][j-1].first;
			father[i][j].second = max(father[i][j-1].second,father[father[i][j-1].first][j-1].second);
		}
	}
}

ll querylca(int a,int b){
	if(a==b) return 0;
	if(depth[a]>depth[b]) swap(a,b);
	ll r = 0;
	for(int i=9;i>=0;i--){
		if(depth[b]==depth[a]) break;
		if(depth[father[b][i].first]>=depth[a]){
			r = max(r,father[b][i].second);
			b = father[b][i].first;
		}
	}
	if(a==b) return r;
	for(int i=9;i>=0;i--){
		if(father[a][i].first!=father[b][i].first){
			r = max({r,father[a][i].second,father[b][i].second});
			a = father[a][i].first;
			b = father[b][i].first;
		}
	}
	r = max({r,father[a][0].second,father[b][0].second});
	a = father[a][0].first;b = father[b][0].first;
	assert(a==b);
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	queue<e> ask;
	dsu mst;
	mst.init(n);
	e edgeset[m];
	for(int i=0;i<m;i++) cin>>edgeset[i].to>>edgeset[i].from>>edgeset[i].w;
	sort(edgeset,edgeset+m,[](const e &a,const e &b){return a.w<b.w;});
	ll mstv = 0;
	for(int i=0;i<m;i++){
		int a,b;ll w;
		a = edgeset[i].to;
		b = edgeset[i].from;
		w = edgeset[i].w;
		if(mst.query(a)!=mst.query(b)){
				mstv+=w;
				mst.join(a,b);
				side[a].push_back({b,w});
				side[b].push_back({a,w});
		}else{
			ask.push({a,b,w});
		}
	}
	
	// check connect
	int h=mst.query(1);
	for(int i=2;i<=n;i++){
		if(mst.query(i)!=h){
			cout<<"-1 -1\n";
			return 0;
		}
	}
	for(int i=0;i<10;i++) father[1][i] = {1,0};
	dfs(1,1);
	buildlca();
	ll smst=LONG_LONG_MAX;
	while(ask.size()){
		e q = ask.front();
		ask.pop();
		smst = min(smst,mstv-querylca(q.to,q.from)+q.w);
	}
	cout<<mstv<<" "<<(((smst==LONG_LONG_MAX)?(-1):(smst)))<<"\n";
	return 0;
}
