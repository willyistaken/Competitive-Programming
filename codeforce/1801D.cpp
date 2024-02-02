#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 805;
vector<ll> tdis[N];
pair<ll,ll> ans[N];
ll w[N];
vector<pair<int,int> > side[N];
void dijk(vector<ll> &dis,int p){
	dis[p]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;
	pq.push({0,p});
	while(pq.size()){
		auto cur = pq.top();
		pq.pop();
		if(cur.first!=dis[cur.second]) continue;
		for(auto i : side[cur.second]){
			if(dis[i.first]>dis[cur.second]+i.second){
				dis[i.first]=dis[cur.second]+i.second;
				pq.push({dis[i.first],i.first});
			}
		}
	}

}


void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		tdis[i].resize(n+1);
		fill(tdis[i].begin(),tdis[i].end(),1e18);
		side[i].clear();
		ans[i] = {1e18,1e18};
	}
	int m;cin>>m;
	int P;cin>>P;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=0;i<m;i++){
		int a,b,s;cin>>a>>b>>s;
		side[a].push_back({b,s});
	}
	for(int i=1;i<=n;i++) dijk(tdis[i],i);
	vector<bool> taken(n+1,0);
	ans[1] = {0,-P};
	for(int i=1;i<=n;i++){
		pair<pair<ll,ll>,int> cur = {{1e18,1e18},-1};
		for(int j=1;j<=n;j++) if(!taken[j]) cur = min(cur,{ans[j],j});
		if(cur.second==-1) break;
		for(int k=1;k<=n;k++){
			if(k==cur.second) continue;
			ll bdis = tdis[cur.second][k];
			if(bdis>=1e18) continue;
			ll days = (bdis+cur.first.second+w[cur.second]-1)/w[cur.second];
			days = max(days,0LL);
			ll leftfuel = (-cur.first.second)+(w[cur.second]*days)-bdis;
			ans[k] = min(ans[k],{cur.first.first+days,-leftfuel});
		}
		taken[cur.second]=1;
	}
	if(ans[n].first!=1e18){
		cout<<ans[n].first<<"\n";
	}else{
		cout<<-1<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
