#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
vector<pair<int,int> > side[N];
int n,m;

void calc(int s,vector<ll> &dis){
	fill(dis.begin(),dis.end(),1e18);
	dis[s]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> >> pq;
	pq.push({0,s});
	while(pq.size()){
		auto cur = pq.top();
		pq.pop();
		if(dis[cur.second]!=cur.first) continue;
		for(auto i : side[cur.second]){
			if(dis[i.first]>dis[cur.second]+i.second){
				dis[i.first]=dis[cur.second]+i.second;
				pq.push({dis[i.first],i.first});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int s,t;cin>>s>>t;
	int u,v;cin>>u>>v;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		side[a].push_back({b,c});
		side[b].push_back({a,c});
	}
	vector<ll> diss(n+1);
	calc(s,diss);
	vector<ll> disu(n+1);
	calc(u,disu);
	vector<ll> dist(n+1);
	calc(t,dist);
	vector<ll> disv(n+1);
	calc(v,disv);
	vector<int> topo(n);
	for(int i=0;i<n;i++) topo[i]=i+1;
	sort(topo.begin(),topo.end(),[&](const int a,const int b){return diss[a]<diss[b];});
	ll ans = disu[v];
	vector<ll> ogdisu = disu;
	for(auto i:topo){
		if(diss[i]+dist[i]!=diss[t]) continue;
		for(auto e : side[i]){
			if(diss[e.first]+e.second==diss[i]){
				disu[i]	=min(disu[i],disu[e.first]);
			}
		}
		ans = min(ans,disu[i]+disv[i]);
	}
	for(auto i:topo){
		if(diss[i]+dist[i]!=diss[t]) continue;
		for(auto e : side[i]){
			if(diss[e.first]+e.second==diss[i]){
				disv[i]	=min(disv[i],disv[e.first]);
			}
		}
		ans = min(ans,disv[i]+ogdisu[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
