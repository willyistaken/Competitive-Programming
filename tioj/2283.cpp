#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


vector<vector<int> > group;
vector<vector<int> > ingroup;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	group.resize(m);
	ingroup.resize(n);
	int groupw[m];
	for(int i=0;i<m;i++){
		int k;cin>>k;
		cin>>groupw[i];
		for(int j=0;j<k;j++){
			int p;cin>>p;p--;
			group[i].push_back(p);
			ingroup[p].push_back(i);
		}
	}
	
	ll dis[n];
	fill(dis,dis+n,1e18);
	dis[0]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	pq.push({0,0});
	bool done[m]={0};
	
	while(pq.size()){
		pair<ll,int> cur = pq.top();
		pq.pop();
		if(dis[cur.second]!=cur.first) continue;
		for(auto g : ingroup[cur.second]){
			if(done[g]) continue;
			done[g]=1;
			for(auto o : group[g]){
				if(o==cur.second) continue;
				if(dis[o]>dis[cur.second]+groupw[g]){
					dis[o] = dis[cur.second]+groupw[g];
					pq.push({dis[o],o});
				}
			}
		}
	}
	ll maxd=0;
	for(int i=0;i<n;i++) maxd = max(maxd,dis[i]);
	if(maxd>5e17) cout<<-1<<"\n";
	else cout<<maxd<<"\n";

	return 0;
}
