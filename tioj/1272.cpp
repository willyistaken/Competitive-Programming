//sometimes tree-flatten>HLC
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,m;
struct bit{
	vector<int> arr;
	void init(){
		arr.resize(n+1,0);
	}
	void add(int ind,int v){
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind & -ind);
		}
	}
	int query(int ind){
		int ans=0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}
};

vector<vector<int> > side;
vector<pair<int,int> > treerange;
int t;

void dfs(int r){
	treerange[r].first = ++t;
	for(auto i : side[r]){
		dfs(i);
	}
	treerange[r].second = t;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	treerange.resize(n+1);
	side.resize(n+1);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int a;cin>>a;
			side[i].push_back(a);
		}
	}
	dfs(1);
	bit fen;
	fen.init();
	while(m--){
		int type,b;cin>>type>>b;
		if(type){
			cout<<(fen.query(treerange[b].first) & 1)<<"\n";	
		}else{
			fen.add(treerange[b].first,1);
			fen.add(treerange[b].second+1,-1);
		}
	}
	return 0;
}
