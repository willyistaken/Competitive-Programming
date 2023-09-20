#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
vector<pair<int,int> > side[4*N];
int b;
void addto(int x,int l,int r,int L,int R,int t){
	if(l==L && r ==R){
		side[t].push_back({x,1});
		return ;
	}
	int M = (L+R)/2;
	if(r<=M) addto(x,l,r,L,M,2*t);
	else if(l>=M) addto(x,l,r,M,R,2*t+1);
	else{
		addto(x,l,M,L,M,2*t);
		addto(x,M,r,M,R,2*t+1);
	}
}
int ntot[N];
void built(int ind,int l,int r){
	if(r-l==1){
		ntot[l]=ind;
		return;
	}
	int m = (l+r)/2;
	side[2*ind].push_back({ind,0});
	side[2*ind+1].push_back({ind,0});
	built(2*ind,l,m);
	built(2*ind+1,m,r);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	built(1,1,n+1);
	for(int i=1;i<=n;i++){
		int l,r;cin>>l>>r;
		addto(ntot[i],l,r+1,1,n+1,1);
	}
	vector<ll> dis1(4*n+5,1e9);
	vector<ll> disn(4*n+5,1e9);
	dis1[ntot[1]]=0;
	disn[ntot[n]]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,ntot[1]});
	while(pq.size()){
		pair<int,int> cur = pq.top();
		pq.pop();
		if(dis1[cur.second]!=cur.first) continue;
		for(auto e : side[cur.second]){
			if(dis1[e.first]>cur.first+e.second){
				dis1[e.first] = cur.first+e.second;
				pq.push({dis1[e.first],e.first});
			}
		}
	}
	pq.push({0,ntot[n]});
	while(pq.size()){
		pair<int,int> cur = pq.top();
		pq.pop();
		if(disn[cur.second]!=cur.first) continue;
		for(auto e : side[cur.second]){
			if(disn[e.first]>cur.first+e.second){
				disn[e.first] = cur.first+e.second;
				pq.push({disn[e.first],e.first});
			}
		}
	}
	for(int i=1;i<=n;i++){
		side[0].push_back({ntot[i],max(dis1[ntot[i]]-1,0LL)+max(disn[ntot[i]]-1,0LL)+1});
	}
	vector<ll> ans(4*n+5,1e9);
	ans[0]=0;
	pq.push({0,0});
	while(pq.size()){
		pair<int,int> cur = pq.top();
		pq.pop();
		if(ans[cur.second]!=cur.first) continue;
		for(auto e : side[cur.second]){
			if(ans[e.first]>cur.first+e.second){
				ans[e.first] = cur.first+e.second;
				pq.push({ans[e.first],e.first});
			}
		}
	}
	
	int q;cin>>q;
	while(q--){
		int x;cin>>x;
		if(ans[ntot[x]]>n) cout<<-1<<"\n";
		else cout<<ans[ntot[x]]<<"\n";
	}
	return 0;
}

//ans = min(ans,1LL*max(dis1[i]-1,0)+max(disn[i]-1,0)+d[i]+1);
