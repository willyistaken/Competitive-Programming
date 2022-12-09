/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;*/
struct dijkstra{
	int n;
	vector<vector<pair<int,ll> > > side;
	void init(int s){
		side.resize(s);
		n = s;
	}
	void add_edge(int a,int b,ll c){
		side[a].push_back({b,c});
	}
	vector<ll> mindis(int u){
		vector<ll> dis(n);
		fill(dis.begin(),dis.end(),1e18);
		dis[u] = 0;
		priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;
		pq.push({0,u});
		while(pq.size()){
			auto cur = pq.top();
			pq.pop();
			if(dis[cur.second]!=cur.first) continue;
			for(auto i : side[cur.second]){
				if(dis[i.first]>dis[cur.second]+i.second){
					dis[i.first] = dis[cur.second]+i.second;
					pq.push({dis[i.first],i.first});
				}
			}
		}
		return dis;
	}
};
