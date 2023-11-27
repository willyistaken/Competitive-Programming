#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "escape_route.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 5e16
const int Ba = 90;
pair<ll,ll> dis[Ba][Ba][Ba*Ba];
vector<pair<int,int> > side[Ba];
bitset<Ba> reach[Ba];
pair<ll,ll> Tdis[Ba][Ba];
std::vector<long long> calculate_necessary_time(
    int N, int M, long long S, int Q, std::vector<int> A, std::vector<int> B,
    std::vector<long long> L, std::vector<long long> C, std::vector<int> U,
    std::vector<int> V, std::vector<long long> T) {
	for(int i=0;i<N;i++) side[i].clear();
    for(int i=0; i<M; i++) {
        side[A[i]].push_back({B[i],i});
        side[B[i]].push_back({A[i],i});
    }
    for(int e=0; e<M; e++) {
        int x = A[e];
        int y = B[e];
        ll disx[Ba];
        ll disy[Ba];
		for(int i=0;i<N;i++) disx[i]=disy[i]=inf;
        disx[x]=0;
        disy[y]=0;
        bitset<Ba> reachx;
        bitset<Ba> reachy;
        ll T = C[e]-L[e];
        while(true) {
            pair<ll,int> cur = {inf,-1};
            for(int i=0; i<N; i++) if(!reachx[i]) cur = min(cur, {disx[i],i});
            if(cur.first>=inf) break;
            for(auto g : side[cur.second]) {
                if(C[g.second]+cur.first<T)	 continue;
                if(disx[g.first]>cur.first+L[g.second]) disx[g.first]=cur.first+L[g.second];
            }
            reachx[cur.second]=1;
        }
        while(true) {
            pair<ll,int> cur = {inf,-1};
            for(int i=0; i<N; i++) if(!reachy[i]) cur = min(cur, {disy[i],i});
            if(cur.first>=inf) break;
            for(auto g : side[cur.second]) {
                if(C[g.second]-cur.first-L[g.second]-L[e]<T) continue;
                if(disy[g.first]>cur.first+L[g.second]) disy[g.first] = cur.first+L[g.second];
            }
            reachy[cur.second]=1;
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                dis[i][j][2*e] = {T-disx[i],disx[i]+disy[j]+L[e]};
            }
        }
		reachx.reset();
		reachy.reset();
		for(int i=0;i<N;i++) disx[i]=disy[i]=inf;
		disx[x]=0;
		disy[y]=0;
        while(true) {
            pair<ll,int> cur = {inf,-1};
            for(int i=0; i<N; i++) if(!reachx[i]) cur = min(cur, {disx[i],i});
            if(cur.first>=inf) break;
            for(auto g : side[cur.second]) {
                if(C[g.second]-cur.first-L[g.second]-L[e]<T)	 continue;
                if(disx[g.first]>cur.first+L[g.second]) disx[g.first]=cur.first+L[g.second];
            }
            reachx[cur.second]=1;
        }
        while(true) {
            pair<ll,int> cur = {inf,-1};
            for(int i=0; i<N; i++) if(!reachy[i]) cur = min(cur, {disy[i],i});
            if(cur.first>=inf) break;
            for(auto g : side[cur.second]) {
                if(C[g.second]+cur.first<T) continue;
                if(disy[g.first]>cur.first+L[g.second]) disy[g.first] = cur.first+L[g.second];
            }
            reachy[cur.second]=1;
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                dis[i][j][2*e+1] = {T-disy[i],disx[j]+disy[i]+L[e]};
            }
        }
    }
	/*	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<i<<" "<<j<<":";
			for(int e=0;e<2*M;e++) cout<<"("<<dis[i][j][e].first<<" "<<dis[i][j][e].second<<") ";
			cout<<"\n";
		}
	}*/
	
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            sort(dis[i][j],dis[i][j]+2*M);
            for(int e=2*M-2; e>=0; e--) dis[i][j][e].second = min(dis[i][j][e].second,dis[i][j][e+1].second);
        }
    }
	vector<vector<ll> >  dis0(N,vector<ll>(N,0));
    for(int s=0; s<N; s++) {
		reach[s].reset();
        for(int i=0; i<N; i++) dis0[s][i]=inf;
        dis0[s][s]=0;
        while(true) {
            pair<ll,int> cur = {inf,-1};
            for(int i=0; i<N; i++) if(!reach[s][i]) cur = min(cur, {dis0[s][i],i});
            if(cur.first>=inf)	break; 
            for(auto e : side[cur.second]) {
                int mind = e.second;
                if(C[mind]-L[mind]<cur.first) continue;
                if(dis0[s][e.first]>cur.first+L[mind]) {
                    dis0[s][e.first] = cur.first+L[mind];
                }
            }
            reach[s][cur.second]=1;
        }
    }
	{
	bitset<Ba> r;
	for(int s=0;s<N;s++){
		r.reset();
		for(int i=0;i<N;i++) Tdis[s][i] = {100,inf};
		Tdis[s][s]={0,0};
		while(true)	{
			pair<pair<ll,ll>,int>  cur = {{100,inf},-1};
			for(int i=0;i<N;i++){
				if(!r[i]){
					cur = min(cur,{Tdis[s][i],i});
				}
			}
			if(cur.first.first>=100 || cur.first.second>=inf) break;
			for(int i=0;i<N;i++){
				if(dis0[cur.second][i]<S){
					if(Tdis[s][i]>make_pair(cur.first.first+1,dis0[cur.second][i])){
						Tdis[s][i] = make_pair(cur.first.first+1,dis0[cur.second][i]); 
					}
				}
			}
			r[cur.second]=1;
		}
	}
	}
	vector<ll> ans(Q,inf);
	
	
	/*
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<i<<" "<<j<<":"<<"("<<Tdis[i][j].first<<","<<Tdis[i][j].second<<")\n";
		}
	}*/
	
	for(int i=0;i<Q;i++){
		int u = U[i];
		ans[i] = min(ans[i],S-T[i]+((Tdis[u][V[i]].first-1)*S)+Tdis[u][V[i]].second);
		for(int v=0;v<N;v++){
			if(v==u) continue;
			ll  l =-1;
			ll r = 2*M;
			while(r-l>1){
				ll mid = (r+l)/2;
				if(dis[u][v][mid].first>=T[i]) r = mid;
				else l = mid;
			}
			if(r>=2*M) continue;
			if(dis[u][v][r].second+T[i]<S && dis[u][v][r].second>0){
//				cout<<i<<":"<<v<<"\n";
				if(v==V[i]){
					ans[i] = min(ans[i],dis[u][v][r].second);	
				}else{
					ans[i] = min(ans[i],S-T[i]+((Tdis[v][V[i]].first-1)*S)+Tdis[v][V[i]].second);
				}
			}
		}
	}
	return ans;
}
