#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "escape_route.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 5e16
const int Ba = 90;
ll dis[Ba][Ba];
vector<pair<int,int> > side[Ba];
bitset<Ba> reach[Ba];
pair<ll,ll> Tdis[Ba][Ba];
ll dis0[Ba][Ba];
ll disx[Ba][Ba][Ba];
ll disy[Ba][Ba][Ba];

struct uxy {
    int u;
    int x;
    int y;
    int ind;
    uxy(int _u,int _x,int _y,int _ind) {
        u = _u;
        x = _x;
        y = _y;
        ind = _ind;
    }
};

std::vector<long long> calculate_necessary_time(
    int N, int M, long long S, int Q, std::vector<int> A, std::vector<int> B,
    std::vector<long long> L, std::vector<long long> C, std::vector<int> U,
    std::vector<int> V, std::vector<long long> T) {
    for(int i=0; i<N; i++) side[i].clear();
    for(int i=0; i<M; i++) {
        side[A[i]].push_back({B[i],i});
        side[B[i]].push_back({A[i],i});
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) dis[i][j]=inf;
    }
    vector<pair<ll,uxy> > addedge;
    for(int e=0; e<M; e++) {
        int x = A[e];
        int y = B[e];
        for(int ttt=0; ttt<2; ttt++) {
            for(int i=0; i<N; i++) disx[x][y][i]=disy[x][y][i]=inf;
            disx[x][y][x]=0;
            disy[x][y][y]=0;
            bitset<Ba> reachx;
            bitset<Ba> reachy;
            ll T = C[e]-L[e];
            while(true) {
                pair<ll,int> cur = {inf,-1};
                for(int i=0; i<N; i++) if(!reachx[i]) cur = min(cur, {disx[x][y][i],i});
                if(cur.first>=inf) break;
                for(auto g : side[cur.second]) {
                    if(C[g.second]+cur.first<T)	 continue;
                    if(disx[x][y][g.first]>cur.first+L[g.second]) disx[x][y][g.first]=cur.first+L[g.second];
                }
                reachx[cur.second]=1;
            }
            while(true) {
                pair<ll,int> cur = {inf,-1};
                for(int i=0; i<N; i++) if(!reachy[i]) cur = min(cur, {disy[x][y][i],i});
                if(cur.first>=inf) break;
                for(auto g : side[cur.second]) {
                    if(C[g.second]-cur.first-L[g.second]-L[e]<T) continue;
                    if(disy[x][y][g.first]>cur.first+L[g.second]) disy[x][y][g.first] = cur.first+L[g.second];
                }
                reachy[cur.second]=1;
            }
            for(int i=0; i<N; i++) {
                addedge.push_back({T-disx[x][y][i],uxy(i,x,y,e)});
            }
            reachx.reset();
            reachy.reset();
            swap(x,y);
        }
    }
    sort(addedge.begin(),addedge.end(),[](const pair<ll,uxy> &a,const pair<ll,uxy> &b) {
        return a.first<b.first;
    });

    /*
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
    		cout<<i<<" "<<j<<":";
    		for(int e=0;e<2*M;e++) cout<<"("<<dis[i][j][e].first<<" "<<dis[i][j][e].second<<") ";
    		cout<<"\n";
    	}
    }*/
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
        for(int s=0; s<N; s++) {
            r.reset();
            for(int i=0; i<N; i++) Tdis[s][i] = {100,inf};
            Tdis[s][s]= {0,0};
            while(true)	{
                pair<pair<ll,ll>,int>  cur = {{100,inf},-1};
                for(int i=0; i<N; i++) {
                    if(!r[i]) {
                        cur = min(cur, {Tdis[s][i],i});
                    }
                }
                if(cur.first.first>=100 || cur.first.second>=inf) break;
                for(int i=0; i<N; i++) {
                    if(dis0[cur.second][i]<S) {
                        if(Tdis[s][i]>make_pair(cur.first.first+1,dis0[cur.second][i])) {
                            Tdis[s][i] = make_pair(cur.first.first+1,dis0[cur.second][i]);
                        }
                    }
                }
                r[cur.second]=1;
            }
        }
    }


    vector<ll> ans(Q,inf);
    vector<int> ord(Q);
    for(int i=0; i<Q; i++) ord[i]=i;
    sort(ord.begin(),ord.end(),[&](const int &a,const int &b) {
        return T[a]>T[b];
    });
    /*
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
    		cout<<i<<" "<<j<<":"<<"("<<Tdis[i][j].first<<","<<Tdis[i][j].second<<")\n";
    	}
    }*/
    int cnt = addedge.size();
    cnt--;
    for(int k=0; k<Q; k++) {
        int i = ord[k];
        int u = U[i];
        ans[i] = min(ans[i],S-T[i]+((Tdis[u][V[i]].first-1)*S)+Tdis[u][V[i]].second);
        while(cnt>=0 && addedge[cnt].first>=T[i]) {
            for(int i=0; i<N; i++) {
                uxy cur = addedge[cnt].second;
                dis[cur.u][i] = min(dis[cur.u][i],disx[cur.x][cur.y][cur.u]+L[cur.ind]+disy[cur.x][cur.y][i]);
            }
            cnt--;
        }
        for(int v=0; v<N; v++) {
            if(v==u) continue;
            if(dis[u][v]+T[i]<S && dis[u][v]>0) {
//				cout<<i<<":"<<v<<"\n";
                if(v==V[i]) {
                    ans[i] = min(ans[i],dis[u][v]);
                } else {
                    ans[i] = min(ans[i],S-T[i]+((Tdis[v][V[i]].first-1)*S)+Tdis[v][V[i]].second);
                }
            }
            //if(N>60 && ct>N/2+N/3) break;
        }
    }
    return ans;
}
