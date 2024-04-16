#include "Aoi.h"

namespace {

int variable_example = 0;


}  // namespace

std::string aoi(int N, int M, int Q, int K, std::vector<int> A,
  std::vector<int> B, std::vector<long long> C,
  std::vector<int> T, std::vector<int> X) {
	vector<ll> dis(N,1e18);
	vector<vector<pair<int,ll>> > side(N);
	for(int i=0;i<M;i++){
		side[A[i]].push_back({B[i],i});
		side[B[i]].push_back({A[i],i});
	}
	sort(X.begin(),X.end());
	dis[0]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> >> pq;
	pq.push_back({0,0});
	vector<int> prev(N,0);
	prev[0]=-1;
	while(pq.size()){
		auto cur = pq.top()	;
		pq.pop();
		int u = cur.second;
		if(dis[u]!=cur.first) continue;
		for(auto i : side[u]){
			if(dis[i.first]>dis[u]+C[i.second]){
				prev[i.first]=i.second;
				dis[i.first]=dis[u]+C[i.second];
				pq.push({dis[i.first],i.first});
			}
		}
	}
	vector<int> P(K);
	vector<bool> U(K);
	for(int i=1;i<N;i++){
		int f = lower_bound(X.begin(),X.end(),prev[i])-X.begin();
		if(f<X.size() && X[f]==prev[i]) P[f]=1;
	}
	for(int i=0;i<K;i++){
		if(dis[A[X[i]]]>dis[B[X[i]]]) U[i]=1;
		else U[i]=0;
		if(!P[i]) P[i]=-1;
		else{
			int cur = U[i]?(B[X[i]]):(A[X[i]]);
			while(cur){
				int e = prev[cur];
				int f = lower_bound(X.begin(),X.end(),e)-X.begin();
				if(f<X.size() && X[f]==e){
					P[i]=e;
					break;
				}
				int u = A[e];
				int v = B[e];
				if(dis[u]>dis[v]) swap(u,v);
				cur = u;
			}
			if(cur==0) P[i]=-1;
		}
	}
	vector<int> Qu(Q);
	
	
}
