#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pair;
#define F first
#define S second
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		vector<Pair > dis(n);
		fill(dis.begin(),dis.end(),(Pair){1e9,1e9});
		vector<vector<Pair> > side(n);
		for(int i=0;i<m;i++){
			int a,b,w;cin>>a>>b>>w;
			side[a].push_back({b,w});
			side[b].push_back({a,w});
		}
		int st,ed;cin>>st>>ed;
		priority_queue<Pair,vector<Pair>,greater<Pair> > pq;
		dis[st].F=0;
		pq.push({0,st});
		while(pq.size()){
			int cur = pq.top().S;int d = pq.top().F;pq.pop();
			for(auto i : side[cur]){
				if(d+i.S<dis[i.F].F){
					dis[i.F].S = dis[i.F].F;
					dis[i.F].F = d+i.S;
					pq.push({dis[i.F].F,i.F});
				}
				if(d+i.S>dis[i.F].F && d+i.S<dis[i.F].S){
					dis[i.F].S =d+i.S;
					pq.push({dis[i.F].S,i.F});
				}
			}
		}
		cout<<((dis[ed].S>5e8)?(-1):(dis[ed].S))<<"\n";
	}

	return 0;
}
