#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int n,m,q;
struct Query{
	int a,b;
	ll x,y;
	int ans;
};
struct request{
	int node;
	ll v;
};
const int N = 1e5+5;

vector<int> side[N];
vector<request> Req;
vector<Query> Que;

// tree stuff
pair<int,int> dep[N];
int father[N][20];
int t;
void dfs(int cur){
	dep[cur].first=++t;
	for(auto i : side[cur]){
		if(!dep[i].first){
			father[i][0] = cur;
			dfs(i);
		}
	}
	dep[cur].second=++t;
}

bool is_father_of(int a,int b){
	return (dep[b].first>=dep[a].first && dep[b].second<=dep[a].second);
}

int lca(int a,int b){
	if(is_father_of(a,b)) return a;
	if(is_father_of(b,a)) return b;
	for(int j=19;j>=0;j--){
		if(!is_father_of(father[b][j],a)) b = father[b][j];
	}
	return father[b][0];
}

//------------------------

//bit stuff
vector<ll> vsum;
vector<ll> cnt;


void add(ll v,int ind,vector<ll> &bit){
	while(ind<=2*n){
		bit[ind]+=v;
		ind+=(ind&-ind);
	}
}
ll query(int ind,vector<ll> &bit){
	ll result = 0;
	while(ind){
		result+=bit[ind];
		ind-=(ind&-ind);
	}
	return result;
}
//--------------------


// total binary search stuff
void do_thing(int l,int r,int mi){
	for(int i=l;i<r;i++){
		if(i<0) continue;
		add(mi*Req[i].v,dep[Req[i].node].first,vsum);
		add(-1*mi*Req[i].v,dep[Req[i].node].second,vsum);
		add(mi,dep[Req[i].node].first,cnt);
		add(-1*mi,dep[Req[i].node].second,cnt);
	}
}

void split(vector<int> &qry,vector<int> &lft,vector<int> &rgt,int k){
	for(auto i : qry){
		long long sum = 0;
		sum+=query(dep[Que[i].a].first,vsum);
		sum+=query(dep[Que[i].b].first,vsum);
		sum-=2*query(dep[lca(Que[i].a,Que[i].b)].first,vsum);
	//	cout<<i<<" "<<sum<<" "<<Que[i].y<<" "<<k<<" -split"<<(sum>Que[i].y)<<"\n";
		if(sum>Que[i].y) lft.push_back(i);
		else rgt.push_back(i);
	}
	vector<int>().swap(qry);
}

void total_BS(int l,int r,vector<int> &qry){
	if(r-l<=1){
		for(auto i : qry) Que[i].ans=l;
		return;
	}
	int mid = (l+r)/2;
	do_thing(l,mid,1);
	vector<int> lft,rgt;	
	split(qry,lft,rgt,mid);
	total_BS(mid,r,rgt);
	do_thing(l,mid,-1);
	total_BS(l,mid,lft);
}

//-----------------------------------


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	Que.resize(q);
	vsum.resize(2*n+1,0);
	cnt.resize(2*n+1,0);
	vector<pair<int,int> > es;
	for(int i=0;i<n-1;i++){
			int a,b;cin>>a>>b;	
			es.push_back({a,b});
			side[a].push_back(b);
			side[b].push_back(a);
	}
	for(int i=0;i<20;i++){
		father[1][i]=1;
	}
	dfs(1);
	for(int j=1;j<20;j++){
		for(int i=2;i<=n;i++){
			father[i][j] = father[father[i][j-1]][j-1];
		}
	}

	for(int i=0;i<m;i++){
		 int p;cin>>p;
		 p--;
		 int c;cin>>c;
		 if(dep[es[p].first]<dep[es[p].second]) swap(es[p].first,es[p].second);
		 Req.push_back({es[p].first,c});
	}
	sort(Req.begin(),Req.end(),[](const request &a,const request &b){return a.v<b.v;});

	vector<int> tmp;		
	for(int i=0;i<q;i++){
		cin>>Que[i].a>>Que[i].b>>Que[i].x>>Que[i].y;
		tmp.push_back(i);
	}
	total_BS(0,m+1,tmp);
	int ttt = 0;	
	vector<int> anssort;
	for(int i=0;i<q;i++){
		anssort.push_back(i);
	}

	sort(anssort.begin(),anssort.end(),[&](const int a,const int b){return Que[a].ans<Que[b].ans;});
	vector<ll> realans(q,0);
	for(int i=0;i<q;i++){
		do_thing(ttt,Que[anssort[i]].ans,1);
		ttt = Que[anssort[i]].ans;
		realans[anssort[i]]+=Que[anssort[i]].x;
		realans[anssort[i]]+=query(dep[Que[anssort[i]].a].first,cnt);
		realans[anssort[i]]+=query(dep[Que[anssort[i]].b].first,cnt);
		realans[anssort[i]]-=2*query(dep[lca(Que[anssort[i]].a,Que[anssort[i]].b)].first,cnt);
	}
	do_thing(ttt,m,1);
	for(int i=0;i<q;i++){
		realans[i]-=query(dep[Que[i].a].first,cnt);
		realans[i]-=query(dep[Que[i].b].first,cnt);
		realans[i]+=2*query(dep[lca(Que[i].a,Que[i].b)].first,cnt);
	}
	for(int i=0;i<q;i++){
		cout<<max(-1LL,realans[i])<<"\n";
	}
	return 0;
}
