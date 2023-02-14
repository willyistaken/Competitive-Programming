#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<int,int>,int> id;

pair<int,int> mp(int l,int r){
	return make_pair(l,r);
}
int n,q,s;
int t = 0;
void built1(int l,int r){
	id[mp(l,r)] = ++t;
	if(r==l) return ;
	int m = (l+r)/2;
	built1(l,m);
	built1(m+1,r);
}

void built2(int l,int r){
	if(r==l) return ;
	id[mp(r,l)] = ++t;
	int m  = (l+r)/2;
	built2(l,m);
	built2(m+1,r);
}

vector<vector<pair<int,ll> > > side;

void builtside(int l,int r){
	if(r==l) return ;
	int m = (l+r)/2;
	side[id[mp(l,r)]].push_back({id[mp(l,m)],0});	
	side[id[mp(l,r)]].push_back({id[mp(m+1,r)],0});
	builtside(l,m);
	builtside(m+1,r);
}
void builtside2(int l,int r,int p){
	if(p){
		side[id[mp(r,l)]].push_back({p,0});
	}
	if(l==r) return ;
	int m = (l+r)/2;
	builtside2(l,m,id[mp(r,l)]);	
	builtside2(m+1,r,id[mp(r,l)]);
}

void vtolr(int v,int l,int r,int L,int R,ll w){
	if(l==L && r==R){
		side[id[mp(v,v)]].push_back({id[mp(L,R)],w});
		return ;
	}
	int M = (L+R)/2;
	if(r<=M) vtolr(v,l,r,L,M,w);
	else if(l>M) vtolr(v,l,r,M+1,R,w);
	else{
		vtolr(v,l,M,L,M,w);
		vtolr(v,M+1,r,M+1,R,w);
	}
}

void lrtov(int v,int l,int r,int L,int R,ll w){
	if(l==L && r==R){
		side[id[mp(R,L)]].push_back({id[mp(v,v)],w});
		return ;
	}
	int M = (L+R)/2;
	if(r<=M) lrtov(v,l,r,L,M,w);
	else if(l>M) lrtov(v,l,r,M+1,R,w);
	else{
		lrtov(v,l,M,L,M,w);
		lrtov(v,M+1,r,M+1,R,w);
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q>>s;				
	built1(1,n);
	built2(1,n);
	side.resize(t+1);
	builtside(1,n);
	builtside2(1,n,0);
	while(q--){
		int type;cin>>type;
		if(type==1){
			int v,u;cin>>v>>u;
			ll w;cin>>w;
			side[id[mp(v,v)]].push_back({id[mp(u,u)],w});
		}
		if(type==2){
			int v,l,r;cin>>v>>l>>r;
			ll w;cin>>w;
			vtolr(v,l,r,1,n,w);
		}
		if(type==3){
			int v,l,r;cin>>v>>l>>r;
			ll w;cin>>w;
			lrtov(v,l,r,1,n,w);
		}
	}
	s = id[mp(s,s)];
	vector<ll> dis(t+1,1e17);
	dis[s]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	pq.push({0,s});
	while(pq.size()){
		auto cur =pq.top();
		pq.pop();
		if(cur.first!=dis[cur.second]) continue;
		for(auto i : side[cur.second]){
			if(i.second+cur.first<dis[i.first]){
				dis[i.first] = i.second+cur.first;
				pq.push({dis[i.first],i.first});
			}
		}
	}
	for(int i=1;i<=n;i++){
		int d = id[mp(i,i)];
		if(dis[d]>=1e17) cout<<-1<<" ";
		else cout<<dis[d]<<" ";
	}
	cout<<"\n";
	return 0;
}
