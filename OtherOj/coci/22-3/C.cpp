#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

/* algorithm:
find shortest path length and second shortest path length
if(spl+1!=sspl) no such edge exist

build sp dag

build ssp dag

if edge is a neccersary path in sp dag and not ssp dag it is answer else it is not

not sure how to do this: neccersary path in dag, it is not really a dag , it is a bridge;

*/
#define mkp make_pair
#define ff first
#define ss second
int n,m;
struct edge {
    int from;
    int to;
	int ind;
    int w;
};

void get_dis(vector<vector<ll> > &dis,const vector<vector<edge> > &side,int s) {
    for(int i=0; i<n; i++) {
        dis[i][0]=1e18;
        dis[i][1]=1e18;
    }
    dis[s][0]=0;
    priority_queue<pair<ll,pair<int,bool> >,vector<pair<ll,pair<int,bool> >>,greater<pair<ll,pair<int,bool> > > > pq;
    pq.push(mkp(0,mkp(s,0)));
    while(pq.size()) {
        auto cur = pq.top();
        pq.pop();
        if(cur.ff!=dis[cur.ss.ff][cur.ss.ss]) continue;
        for(auto e : side[cur.ss.ff]) {
            ll d = cur.ff+e.w;
            if(d<dis[e.to][0]) {
                dis[e.to][1] = dis[e.to][0];
                dis[e.to][0]=d;
                pq.push(mkp(dis[e.to][1],mkp(e.to,1)));
                pq.push(mkp(dis[e.to][0],mkp(e.to,0)));
            } else if(d>dis[e.to][0] && d<dis[e.to][1]) {
                dis[e.to][1] = d;
                pq.push(mkp(dis[e.to][1],mkp(e.to,1)));
            }
        }
    }
}

int t;
vector<int> low;
vector<int> vis;
vector<vector<edge> > side(n);
void dfs(int cur,int p,int ind,const vector<bool> &mask,vector<bool> &result){
	vis[cur]=low[cur]=++t;
	for(auto e : side[cur]){
		if(!mask[e.ind]) continue;
		if(e.to==p) continue;
		if(!vis[e.to]){
			dfs(e.to,cur,e.ind,mask,result);
			low[cur] = min(low[cur],low[e.to]);
		}else{
			low[cur] = min(low[cur],vis[e.to]);
		}
	}
	if(ind>=0 && low[cur]==vis[cur]) result[ind]=1;
}


void get_B(vector<bool> &mask,vector<bool> &result){
	t = 0;
	fill(low.begin(),low.end(),0);
	fill(vis.begin(),vis.end(),0);
	dfs(0,-1,-1,mask,result);
}

void solve() {
    cin>>n>>m;
	low.resize(n);
	vis.resize(n);
	side.clear();
	side.resize(n);
    vector<edge> edgeset;
    for(int i=0; i<m; i++) {
        int a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        side[a].push_back({a,b,i,w});
        side[b].push_back({b,a,i,w});
        edgeset.push_back({a,b,i,w});
    }
    vector<vector<ll> > adis(n,vector<ll>(2));
    vector<vector<ll> > bdis(n,vector<ll>(2));
    get_dis(adis,side,0);
    get_dis(bdis,side,n-1);
    vector<bool> insp(m,0);
    vector<bool> inssp(m,0);
    if(adis[n-1][0]+1!=adis[n-1][1]) {
        cout<<0<<"\n\n";
        return;
    }
    for(int i=0; i<m; i++) {
        int a = edgeset[i].from;
        int b = edgeset[i].to;
        int w = edgeset[i].w;
        for(int _=0; _<2; _++) {
            if(adis[a][0]+w+bdis[b][0]==adis[n-1][0]) {
                insp[i]=1;
            }
            if(adis[a][1]+w+bdis[b][0]==adis[n-1][1]) {
                inssp[i]=1;
            }
            if(adis[a][0]+w+bdis[b][1]==adis[n-1][1]) {
                inssp[i]=1;
            }
            if(adis[a][0]+w+bdis[b][0]==adis[n-1][1]) {
                inssp[i]=1;
			}
            swap(a,b);
        }
    }
	/*
	for(auto i : insp) cout<<i<<" ";
	cout<<"\n";
	for(auto i : inssp) cout<<i<<" ";
	cout<<"\n";
	*/
	
	vector<bool> IsBInSp(m);
	vector<bool> IsBInSsp(m);
	get_B(insp,IsBInSp);
	get_B(inssp,IsBInSsp);
	/*
	for(auto i : IsBInSp) cout<<i<<" ";
	cout<<"\n";
	for(auto i : IsBInSsp) cout<<i<<" ";
	cout<<"\n";
	*/
	int cnt = 0;
	for(int i=0;i<m;i++){
		if(IsBInSp[i] && !IsBInSsp[i]){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
	for(int i=0;i<m;i++){
		if(IsBInSp[i] && !IsBInSsp[i]){
			cout<<i+1<<' ';
		}
	}
	cout<<"\n";
}




int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int task;
    cin>>task;
    while(task--) {
        solve();
    }
    return 0;
}
