#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,m;
struct e{
		int to;
		int from;
		int w;
};
vector<pair<int,int> > side[50005];
vector<e> edgeset;

struct dsu{
	vector<int> arr;
	int s;
	void init(int S){
			s = S+1;
			arr.resize(s,0);
			for(int i=0;i<s;i++){
					arr[i] = i;
			}
	}
	int query(int ind){
			if(arr[ind]==ind) return ind;
			arr[ind] = query(arr[ind]);
			return arr[ind];
	}

	void join(int a,int b){
			arr[query(a)] = arr[query(b)];
			return ;
	}
};

int depth[50005];
bitset<50005> vis;
pair<int,int> father[50005][18];
void dfs(int r,int p){
	vis[r]=1;
	depth[r] = depth[p]+1;
	for(auto i : side[r]){
		if(i.first!=p) dfs(i.first,r);
		else father[r][0] = {p,i.second};
	}
}

void fatherinit(){
	for(int j=1;j<18;j++){
			for(int i=1;i<=n;i++){
					father[i][j].first = father[father[i][j-1].first][j-1].first;
					father[i][j].second = max(father[i][j-1].second,father[father[i][j-1].first][j-1].second);
			}
	}
}

int querylca(int a,int b){
	if(depth[a]>depth[b]) swap(a,b);
	int r = 0;
	for(int i=17;i>=0;i--){
			if(depth[b]==depth[a]) break;
			if(depth[father[b][i].first]>=depth[a]){
				r = max(r,father[b][i].second);
				b = father[b][i].first;
			}
	}
	if(a==b) return r;
	for(int i=17;i>=0;i--){
		if(father[a][i].first!=father[b][i].first){
			r = max(r,father[a][i].second);
			r = max(r,father[b][i].second);
			a = father[a][i].first;
			b = father[b][i].first;
		}
	}
	if(a!=b){
		r = max(father[a][0].second,r);
		r = max(father[b][0].second,r);
	}
//	assert(father[a][0].first==father[b][0].first);
	return r;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
			int a,b,w;cin>>a>>b>>w;
			edgeset.push_back({a,b,w});
	}
	sort(edgeset.begin(),edgeset.end(),[](const e &a,const e &b){return a.w<b.w;});
	dsu mst;
	mst.init(n);
	for(int i=0;i<m;i++){
			if(mst.query(edgeset[i].to)!=mst.query(edgeset[i].from)){
				mst.join(edgeset[i].to,edgeset[i].from);
				side[edgeset[i].to].push_back({edgeset[i].from,edgeset[i].w});
				side[edgeset[i].from].push_back({edgeset[i].to,edgeset[i].w});
			}
	}
	vis.reset();
	for(int i=1;i<=n;i++){
			if(!vis[i]) {
				for(int k=0;k<18;k++){
					father[i][k] = make_pair(i,0);
				}
				dfs(i,0);
			}
	}
	fatherinit();		
	/*for(int i=1;i<=n;i++){
		cout<<i<<":";
		for(int j=0;j<18;j++) cout<<father[i][j].first<<"\\"<<father[i][j].second<<" ";
		cout<<"\n";
	}*/
	int q;cin>>q;
	while(q--){
			int a,b;cin>>a>>b;
			if(a==b) cout<<0<<"\n";
			else if(mst.query(a)!=mst.query(b)) cout<<-1<<"\n";
			else{
				cout<<querylca(a,b)<<"\n";	
			}
	}

	return 0;
}
