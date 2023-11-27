#include "escape_route.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Ba = 90; bitset<Ba> reach[90];
ll dis[90][90];
std::vector<long long> calculate_necessary_time(
    int N, int M, long long S, int Q, std::vector<int> A, std::vector<int> B,
    std::vector<long long> L, std::vector<long long> C, std::vector<int> U,
    std::vector<int> V, std::vector<long long> T) {
	vector<vector<pair<int,int> >> side(N);
	for(int i=0;i<M;i++){
		side[A[i]].push_back({B[i],i});
		side[B[i]].push_back({A[i],i});
	}
	for(int i=0;i<N;i++) reach[i].reset();
 
	// pre	(n^3)
		for(int s=0;s<N;s++){
			for(int i=0;i<N;i++) dis[s][i]=1e18;
			dis[s][s]=0;
			while(true){
				pair<ll,int> cur = {1e18,-1};
				for(int i=0;i<N;i++) if(!reach[s][i]) cur = min(cur,{dis[s][i],i});
				if(cur.first>=1e18)	break;
				for(auto e : side[cur.second]){
					int mind = e.second;
					if(C[mind]-L[mind]<cur.first) continue;
					if(dis[s][e.first]>cur.first+L[mind]){
						dis[s][e.first] = cur.first+L[mind];
					}
				}
				reach[s][cur.second]=1;
			}
		}
	// preend
 
	vector<ll>  ans(Q);
	for(int q=0;q<Q;q++){
		vector<ll> qdis(N,1e18);
		bitset<Ba> qreach;
		qreach.reset();
		qdis[U[q]]=0;
		while(true){
			pair<ll,int> cur = {1e18,-1};
			for(int i=0;i<N;i++) if(!qreach[i]) cur = min(cur,{qdis[i],i});
			if(cur.first>=1e18) break;
			for(auto e : side[cur.second]){
				int mind = e.second;
				if(C[mind]-L[mind]-T[q]<cur.first) continue;
				if(qdis[e.first]>cur.first+L[mind]){
					qdis[e.first] = cur.first+L[mind];
				}
			}
			qreach[cur.second]=1;
		}
		for(int i=0;i<N;i++) if(qdis[i]>S-T[q]) qdis[i]=1e18;
		if(qdis[V[q]]<1e18){
			ans[q] = qdis[V[q]];
			continue;
		}
		ll qans = 1e18;
		queue<pair<int,int> > que;
		bitset<Ba> reachq;
		for(int i=0;i<N;i++){
			if(qdis[i]<1e18 && !reachq[i]) {
				que.push({i,1});
				reachq[i]=1;
			}
		}
		while(que.size()){
			auto cur = que.front();
			que.pop();
			if(dis[cur.first][V[q]]<1e18) qans = min(qans,(S*cur.second)+dis[cur.first][V[q]]);
			for(int j=0;j<N;j++){
				if(reach[cur.first][j] && !reachq[j]){
					que.push({j,cur.second+1});
					reachq[j]=1;
				}
			}
		}
		ans[q] = qans-T[q];
	}
  return ans;
}
