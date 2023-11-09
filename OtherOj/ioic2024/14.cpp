#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e5+5;
int n,m;
vector<pair<int,int> > side[N];
const int MOD = 1e9+7;
void get(int s,vector<int>& cnt,vector<ll>& dis){
	dis[s]=0;
	cnt[s]=1;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> >> pq;
	pq.push({0,s});
	while(pq.size()){
		auto cur = pq.top();
		pq.pop();
		if(cur.first!=dis[cur.second]) continue;
		for(auto i : side[cur.second]){
			if(dis[i.first]>dis[cur.second]+i.second){
				dis[i.first]=dis[cur.second]+i.second;
				cnt[i.first] = cnt[cur.second];
				pq.push({dis[i.first],i.first});
			}else if(dis[i.first]==dis[cur.second]+i.second){
				cnt[i.first] = (cnt[i.first]+cnt[cur.second])%MOD;
			}
		}
	}
	return ;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q,s,t;cin>>n>>m>>q>>s>>t;	
	vector<int> Q(q);
	for(int i=0;i<q;i++) cin>>Q[i];
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		side[a].push_back({b,c});
		side[b].push_back({a,c});
	}
	vector<int> cnts(n+1,0),cntt(n+1,0);
	vector<ll> diss(n+1,1e18),dist(n+1,1e18);
	get(s,cnts,diss);
	get(t,cntt,dist);
	for(auto v : Q){
		cout<<diss[v]+dist[v]<<" "<<(1LL*cnts[v]*cntt[v])%MOD<<"\n";
	}
	return 0;
}
