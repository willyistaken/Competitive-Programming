#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int n,m,q;
struct query{
	int a,b;
	int x,y;
	int ans;
};
struct request{
	int node;
	int v;
};
vector<query> Que;
const int N = 1e5+5;

vector<int> side[N];
vector<request> Req;
pair<int,int> dep[N];
int t;
void dfs(int cur){
	dep[cur].first=++t;
	for(auto i : side[cur]){
		if(!dep[i].first){
			dfs(i);
		}
	}
	dep[cur].second=++t;
}
vector<ll> bit;
void add(ll v,int ind){
	while(ind<=2*n){
		bit[ind]+=v;
		ind+=(ind&-ind);
	}
}
ll query(int ind){
	ll result = 0;
	while(ind){
		result+=bit[ind];
		ind-=(ind&-ind);
	}
	return result;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	Que.resize(q);
	bit.resize(2*n+1,0);
	vector<pair<int,int> > es;
	for(int i=0;i<n-1;i++){
			int a,b;cin>>a>>b;	
			es.push_back({a,b});
			side[a].push_back(b);
			side[b].push_back(a);
	}
	dfs(1);
	for(int i=0;i<m;i++){
		 int p;cin>>p;
		 p--;
		 int c;cin>>c;
		 if(dep[es[p].first]<dep[es[p].second]) swap(es[p].first,es[p].second);
		 Req.push_back({es[p].first,c});
	}
		
	return 0;
}
