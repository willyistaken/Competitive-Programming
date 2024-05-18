#include "swap.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	int a;
	int b;
	int w;
};
vector<edge> es;
int n;
int m;
vector<vector<int> > side;
vector<int> gtime;
vector<pair<int,int> > p;
vector<bool> cyc;
vector<int> maxd;
vector<vector<int> > ele;
vector<int> deg;
int query(int x){
	while(p[x].first!=x) x=p[x].first;
	return x;
}

void init(int N, int M,std::vector<int> U, std::vector<int> V, std::vector<int> W) {
	n = N;
	m = M;
	side.resize(n);
	gtime.resize(n,-1);
	p.resize(n);
	cyc.resize(n);
	maxd.resize(n);
	ele.resize(n);
	deg.resize(n,0);
	for(int i=0;i<M;i++){
		es.push_back({U[i],V[i],W[i]});
	}
	sort(es.begin(),es.end(),[](const edge &x,const edge &y){return x.w<y.w;});
	for(int i=0;i<n;i++){
		ele[i].push_back(i)	;
		p[i]={i,0};
	}
	for(int i=0;i<m;i++){
		int u = es[i].a;
		int v = es[i].b;
		deg[es[i].a]++;
		deg[es[i].b]++;
		u = query(u);
		v = query(v);
		if(u==v){
			cyc[u]=1;
			maxd[u] = max({maxd[u],deg[es[i].a],deg[es[i].b]});
			if(gtime[u]==-1){
				for(auto e : ele[u]) gtime[e]=es[i].w;
			}
			continue;
		}
		if(ele[u].size()<ele[v].size()) swap(u,v);
		p[v] = {u,es[i].w};
		maxd[u] = max({maxd[u],deg[es[i].a],deg[es[i].b],maxd[v]});
		cyc[u] = cyc[u]|cyc[v];
		if(maxd[u]>2 || cyc[u]){
			if(gtime[u]==-1){
				for(auto e : ele[u]) gtime[e]=es[i].w;
			}
			if(gtime[v]==-1){
				for(auto e : ele[v]) gtime[e]=es[i].w;
			}
		}
		for(auto e : ele[v]) ele[u].push_back(e);
	}
}

int getMinimumFuelCapacity(int X, int Y) {
	int mc=0;	
	int x = X;
	int y = Y;
	while(x!=y){
		if(ele[x].size()<ele[y].size()) swap(x,y);
		mc = max(mc,p[y].second);
		y = p[y].first;
	}
	if(gtime[X]==-1 || gtime[Y]==-1) return -1;
	return max({mc,gtime[X],gtime[Y]});
}
