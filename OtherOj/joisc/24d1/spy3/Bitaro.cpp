#include "Bitaro.h"
#include<queue>
#include<iostream>

namespace {

int variable_example = 0;

int function_example(int a, int b) { return a + b; }

}  // namespace

using namespace std;
typedef long long ll;
void bitaro(int N, int M, int Q, int K, std::vector<int> A, std::vector<int> B,
            std::vector<long long> C, std::vector<int> T, std::vector<int> X,
            std::string s) {
  	for(int i=0;i<K;i++){
		ll w = 0;
		for(int b=0;b<40;b++){
			int k = (s[40*i+b]=='1');
			w+=(1<<b)*k;
		}
		C[X[i]]=w;
	}
	vector<ll> dis(N,1e18);
	vector<vector<pair<int,ll>> > side(N);
	for(int i=0;i<M;i++){
		side[A[i]].push_back({B[i],i});
		side[B[i]].push_back({A[i],i});
	}
	dis[0]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> >> pq;
	pq.push({0,0});
	vector<int> prev(N,0);
	prev[0]=-1;
	vector<bool> vis(N,0);
	while(pq.size()){
		auto cur = pq.top()	;
		pq.pop();
		int u = cur.second;
		if(vis[u]) continue;
		if(dis[u]!=cur.first) continue;
		vis[u]=1;
		for(auto i : side[u]){
			if(dis[i.first]>dis[u]+C[i.second]){
				prev[i.first]=i.second;
				dis[i.first]=dis[u]+C[i.second];
				pq.push({dis[i.first],i.first});
			}
		}
	}

	for(int i=0;i<Q;i++){
		int cur = T[i];
		vector<int> ans;
		while(cur){
			int e = prev[cur];
			ans.push_back(e);
			int u = A[e];
			int v = B[e];
			if(dis[u]>dis[v]) swap(u,v);
			cur = u;
		}
		reverse(ans.begin(),ans.end());
		answer(ans);
		for(auto i : ans) cout<<i<<" ";
		cout<<"\n";
	}
}
