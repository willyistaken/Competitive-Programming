#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds
struct BIT{
	vector<int> arr;
	int _n;
	void init(int s){
		arr.resize(s+1,0);
		_n = s;
	}
	void add(int ind,int v){
		while(ind<=_n){
			arr[ind]+=v;
			ind+=(ind & -ind);
		}
	}
	int query(int ind){
		int ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}

};

const int N =2e5+5;
vector<int> side[N];
int t1;
pair<int,int> T1[N];
int P[N][20];
void dfs(int cur){
	T1[cur].first=++t1;
	for(auto i : side[cur]){
		dfs(i);
	}
	T1[cur].second=++t1;
}
bool isanc(int u,int v){
	return (T1[u].first<=T1[v].first && T1[u].second>=T1[v].second);
}
int lca(int u,int v){
	if(isanc(u,v)) return u;
	if(isanc(v,u)) return v;
	for(int j=19;j>=0;j--){
		if(!isanc(P[v][j],u)) v = P[v][j];
	}
	return P[v][0];
}

ll w[N];
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	BIT tree;
	BIT path;
	int n,q;cin>>n>>q;	
	P[1][0]=1;
	for(int i=0;i<n-1;i++){
		int p;cin>>p;	
		side[p].push_back(i+2);
		P[i+2][0]=p;
	}
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++) P[i][j] = P[P[i][j-1]][j-1];
	}
	dfs(1);
	tree.init(2*n+1);
	path.init(2*n+1);
	while(q--){
		int t;cin>>t;
		if(t==1){
			int u,c;cin>>u>>c;	
			w[u]+=c;
			tree.add(T1[u].first,c);
			path.add(T1[u].first,c);
			path.add(T1[u].second,-c);
		}else if(t==2){
			int u,v;cin>>u>>v;
			int c = lca(u,v);
			cout<<path.query(T1[u].first)+path.query(T1[v].first)-2*path.query(T1[c].first)+w[c]<<"\n";
		}else{
			int u;cin>>u;
			cout<<tree.query(T1[u].second)-tree.query(T1[u].first-1)<<"\n";
		}
	}
	return 0;
}
