#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
pair<int,int> par[1005];
int sz[1005];
struct edge{
	int a;
	int b;
	int w;
};

int query(int a){
	while(par[a].first!=a){
		a = par[a].first;
	}
	return a;
}
void join(int a,int b,int w){
	a = query(a);
	b = query(b);
	if(sz[a]<sz[b]) swap(a,b);
	par[b] = {a,w};
	sz[a]+=sz[b];
}
vector<edge> edgeset;
bool out[100005];
bool inroad[100005];
map<pair<int,int>,int> e2n;
int n,m;
void rebuilt(){
	for(int i=1;i<=n;i++){
		par[i] = {i,0};
		sz[i]=1;
	}
	for(int i=0;i<m;i++){
		inroad[i]=0;
		if(out[i]) continue;
		if(query(edgeset[i].a)==query(edgeset[i].b)) continue;
		join(edgeset[i].a,edgeset[i].b,edgeset[i].w);
		inroad[i]=1;
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int k;cin>>k;
	for(int i=0;i<m;i++){
		edge temp;
		cin>>temp.a>>temp.b>>temp.w;
		if(temp.a>temp.b) swap(temp.a,temp.b);
		edgeset.push_back(temp);
	}
	sort(edgeset.begin(),edgeset.end(),[](const edge &a,const edge &b){return a.w<b.w;});
	for(int i=0;i<m;i++){
		e2n[make_pair(edgeset[i].a,edgeset[i].b)]=i;
	}
	rebuilt();
	for(int i=0;i<k;i++){
		int t;cin>>t;
		if(t==1){
			int a,b;cin>>a>>b;
			int ansmax = 0;	
			while(a!=b){
				if(sz[a]<sz[b]) swap(a,b);
				ansmax = max(ansmax,par[b].second);
				b = par[b].first;
			}
			cout<<ansmax<<"\n";
		}
		if(t==2){
			int a,b;cin>>a>>b;	
			if(a>b) swap(a,b);
			int ind = e2n[make_pair(a,b)];
			out[ind]=1;
			if(inroad[ind]){
				rebuilt();
			}
		}
	}
	return 0;
}
