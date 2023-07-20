#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



const int N = 1e5+5;
vector<pair<int,int> > side[N];
ll dis[N];
pair<int,ll> p[N];
int sz[N];

int query(int a){
	while(a!=p[a].first){
		a = p[a].first;
	}
	return a;
}

void join(int a,int b,ll v){
	a = query(a);
	b = query(b);
	if(a==b) return ;
	if(sz[a]>sz[b]) swap(a,b);
	p[a].first=b;
	p[a].second=v;
	sz[b]+=sz[a];
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	for(int i=0;i<m;i++){
		int a,b,w;cin>>a>>b>>w;
		side[a].push_back({b,w});
		side[b].push_back({a,w});
	}
	for(int i=1;i<=n;i++) dis[i]=1e18;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	int k;cin>>k;
	for(int i=0;i<k;i++){
		int g;cin>>g;
		dis[g]=0;
		pq.push({dis[g],g});
	}
	while(pq.size()){
		pair<ll,int> cur= pq.top();
		pq.pop();
		if(cur.first!=dis[cur.second]) continue;
		for(auto e : side[cur.second]){
			if(dis[e.first]>dis[cur.second]+e.second){
				dis[e.first] = dis[cur.second]+e.second;
				pq.push({dis[e.first],e.first});
			}
		}
	}
	vector<int> order;
	for(int i=1;i<=n;i++){
		order.push_back(i);
		p[i] = {i,0};
		sz[i]=1;
	}
	sort(order.begin(),order.end(),[&](const int a,const int b){return dis[a]>dis[b];});
	for(auto i : order){
		for(auto e : side[i]){
			if(dis[e.first]<dis[i] || (dis[e.first]==dis[i] && e.first<i)) continue;
			join(i,e.first,dis[i]);
		}
	}
	int q;cin>>q;
	while(q--){
		int s,t;cin>>s>>t;
		ll minn = 1e18;
		while(s!=t){
			if(sz[s]>sz[t]) swap(s,t);
			minn = min(p[s].second,minn);
			s = p[s].first;
		}
		cout<<minn<<"\n";
	}
	return 0;
}

/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
*/
