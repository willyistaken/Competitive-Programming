#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct edge{
	int a;
	int b;
	int w;
	edge(int _a,int _b,ll _w){
		a=_a;
		b=_b;
		w=_w;
	}
};
const int N = 2e5+5;
bool used[N];
int sz[N];
int a[N];
vector<edge> pot;
vector<pair<int,int> > side[N];

int get_sz(int v,int p = 0){
	sz[v]=1;
	for(auto i : side[v]){
		if(!used[i.first] && i.first!=p){
			sz[v]+=get_sz(i.first,v);
		}
	}
	return sz[v];
}

int centroid(int tsz,int v,int p=0){
	for(auto i : side[v]){
		if(!used[i.first] && p!=i.first){
			if(sz[i.first]>tsz){
				return centroid(tsz,i.first,v);
			}
		}
	}
	return v;
}

void getdis(vector<pair<ll,int> >& arr,int c,ll dis=0,int p=0){
		arr.push_back({dis+a[c],c})	;
		for(auto i : side[c]){
			if(!used[i.first] && i.first!=p){
				getdis(arr,i.first,dis+i.second,c);
			}
		}
}


void add(int v){
	int c = centroid(get_sz(v)/2,v);
	vector<pair<ll,int> > arr;
	getdis(arr,c);
	used[c]=1;
	int k = min_element(arr.begin(),arr.end())-arr.begin();
	for(int i=0;i<arr.size();i++){
		if(i!=k){
			pot.push_back(edge(arr[i].second,arr[k].second,arr[i].first+arr[k].first));		
		}
	}
	for(auto i : side[c]){
		if(!used[i.first]) add(i.first);
	}
}

int P[N];

int query(int a){
	if(P[a]==a) return a;
	return P[a]=query(P[a]);
}

void join(int a,int b){
	a=query(a);b=query(b);
	if(a!=b){
		P[a]=b;
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) P[i]=i;
	for(int i=0;i<n-1;i++){
		int u,v,w;cin>>u>>v>>w;
		side[u].push_back({v,w});
		side[v].push_back({u,w});
	}
	add(1);
	sort(pot.begin(),pot.end(),[](const edge &a,const edge &b){return a.w<b.w;});
	ll ans = 0;
	for(auto e : pot){
		if(query(e.a)!=query(e.b)){
			ans+=e.w;	
			join(e.a,e.b);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
