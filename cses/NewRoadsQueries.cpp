#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct dsu{
	vector<int> arr;
	dsu(int n){
		arr.resize(n);
		for(int i=0;i<n;i++) arr[i] = i;
	}
	int query(int a){
		if(arr[a]==a) return arr[a];
		arr[a] = query(arr[a]);
		return arr[a];
	}
	void join(int a,int b){
		arr[query(a)] = query(b);
	}
};

vector<vector<pair<int,int> > > side;
vector<int> dep;
vector<pair<int,int> > pa[20]; 

void dfs(int cur){
	dep[cur] = dep[pa[0][cur].first]+1;
	for(auto i : side[cur]){
		if(!pa[0][i.first].first){
			pa[0][i.first] = {cur,i.second};
			dfs(i.first);
		}
	}
}

int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	int ans = 0;
	for(int i=19;i>=0;i--){
		if(dep[pa[i][b].first]>=dep[a]) {
			ans = max(ans,pa[i][b].second);
			b = pa[i][b].first;
		}
	}
	if(a==b) return ans;
	for(int i=19;i>=0;i--){
		if(pa[i][a].first!=pa[i][b].first){
			ans = max(ans,pa[i][a].second);
			ans = max(ans,pa[i][b].second);
			a = pa[i][a].first;
			b = pa[i][b].first;
		}
	}
	return max({ans,pa[0][a].second,pa[0][b].second});
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	dsu mydsu(n+1);
	side.resize(n+1);
	for(int i=0;i<m;i++){
		int to;
		int from;
		cin>>to>>from;
		if(mydsu.query(to)!=mydsu.query(from)){
			side[to].push_back({from,i+1});
			side[from].push_back({to,i+1});
			mydsu.join(to,from);
		}
	}
	for(int i=0;i<20;i++){
		pa[i].resize(n+1);
	}
	dep.resize(n+1);
	for(int i=1;i<=n;i++){
		if(!pa[0][i].first) {
			for(int p=0;p<20;p++) pa[p][i] = {i,0};
			dfs(i);
		}
	}
	
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			pa[j][i].first = pa[j-1][pa[j-1][i].first].first;
			pa[j][i].second = max(pa[j-1][i].second,pa[j-1][pa[j-1][i].first].second);
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		if(mydsu.query(a)!=mydsu.query(b)){
			cout<<"-1\n";
			continue;
		}
		cout<<lca(a,b)<<"\n";
	}
		
	return 0;
}
