#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
#define int ll

vector<vector<pair<int,int>> >  side;

void get_dis(int s,vector<ll> &dis){
	dis[s]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;
	pq.push({0,s});
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

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	side.resize(n);
	vector<ll> sdis(n,1e18);	
	vector<ll> tdis(n,1e18);
	int s,t,l;	
	ll k;
	cin>>s>>t>>l>>k;
	s--;
	t--;
	for(int i=0;i<m;i++){
		int a,b,w;cin>>a>>b>>w;	
		a--;
		b--;
		side[a].push_back({b,w});
		side[b].push_back({a,w});
	}
	get_dis(s,sdis);
	get_dis(t,tdis);
	if(sdis[t]<=k){
		cout<<(1LL*n*(n-1)/2)<<"\n";
		return 0;
	}
	sort(tdis.begin(),tdis.end());
	ll ans = 0;
	for(int i=0;i<n;i++){
		ll target = k-l-sdis[i];
		ans+=upper_bound(tdis.begin(),tdis.end(),target)-tdis.begin();
	}
	cout<<ans<<"\n";
	return 0;
}
