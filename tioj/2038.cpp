#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 5005;
vector<int> side[N];
int deg[N];
vector<int> ds[N];

struct dsu{
	struct node{
		int sz=1;
		int pa;
	};
	vector<node> arr;
	void init(int n){
		arr.resize(n+1);	
		for(int i=0;i<=n;i++) arr[i].pa = i;
	}

	int query(int a){
		if(arr[a].pa==a) return a;
		 arr[a].pa = query(arr[a].pa);
		 return arr[a].pa;
	}

	void join(int a,int b){
		a = query(a);
		b = query(b);
		if(a==b) return;
		arr[a].sz = arr[a].sz+arr[b].sz;
		arr[b].pa = a;
	}

} D;

bool vis[N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	stack<int> seq;
	D.init(n);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	for(int i=1;i<=n;i++){
		ds[deg[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int d = 0;d<=n;d++){
			while(ds[d].size() && deg[ds[d].back()]!=d){
				ds[d].pop_back();
			}
			if(ds[d].size()){
				int cur = ds[d].back();
				ds[d].pop_back();
				for(auto i : side[cur]){
					if(!deg[i]) continue;
					deg[i]--;
					deg[cur]--;
					ds[deg[i]].push_back(i);
				}
				seq.push(cur);
				break;
			}
		}
	}
	ll ans = 0;	

	for(int fff=0;fff<n;fff++){
		int cur = seq.top();
		seq.pop();
		vis[cur]=1;
		for(auto k : side[cur]){
			if(!vis[k]) continue;
			deg[cur]++;
			deg[k]++;
			D.join(cur,k);
		}
		ans = max(ans,(1LL*D.arr[D.query(cur)].sz)*deg[cur]);
	}
	cout<<ans<<"\n";



	return 0;
}
