#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const ll inf=1e16;
struct DSU{
	vector<int> P,sz;
	void reset(int n){
		P.resize(n);
		for(int i=0;i<n;i++) P[i]=i;
		sz.resize(n);
		for(int i=0;i<n;i++) sz[i]=1;
	}
	DSU(int n){
		reset(n);
	}
	int find(int a){
		if(P[a]==a) return a;
		P[a] = find(P[a]);
		return P[a];
	}
	bool join(int a,int b){
		a = find(a);
		b = find(b);
		if(sz[a]>sz[b])	swap(a,b);
		if(a!=b){
			P[a]=b;
			sz[b]+=sz[a];
			return 1;
		}
		return 0;
	}
		
};

struct DMST{
	struct edge{
		int l,r;
		int u,v;
		ll w;
		edge(int _l,int _r,int _u,int _v,ll _w):l(_l),r(_r),u(_u),v(_v),w(_w){}
		bool operator<(edge &b){
			return w<b.w;
		}
	};
	vector<edge> Eran;
	vector<tuple<int,int,ll> > edgeset;
	vector<int> prev;
	vector<int> id;
	DSU dsu1,dsu2;
	int realn;
	DMST(vector<tuple<int,int,ll> > Es , int n):edgeset(Es),prev(Es.size()),id(n),dsu1(n),dsu2(n),realn(n){}
	int q= 0;
	void update(int i,ll x){
		q++;
		int u = get<0>(edgeset[i]);
		int v = get<1>(edgeset[i]);
		ll w = get<2>(edgeset[i]);
		Eran.push_back(edge(prev[i],q,u,v,w));
		prev[i]=q;
		get<2>(edgeset[i])=x;
	}
	vector<ll> ans;
	void solve(int l,int r,vector<edge> es,int n,ll cost){
		es.erase(stable_partition(es.begin(),es.end(),[&](const edge& e) {return !(e.r<=l or r<=e.l);}),es.end());	
		dsu1.reset(n);dsu2.reset(n);
		for(auto &e :es){
			if(l<e.l || r>e.r){
				dsu1.join(e.u,e.v);
			}
		}
		for(auto &e:es){
			if(e.l<=l && e.r>=r){
				if(dsu1.join(e.u,e.v)){
					cost+=e.w;
					dsu2.join(e.u,e.v);
				}
			}
		}
		if(r-l==1){
			ans[l]=cost;
			return;
		}
		int cnt=0;
		for(int i=0;i<n;i++) if(dsu2.find(i)==i) id[i]=cnt++;
		dsu1.reset(cnt);
		for(auto &e :es){
			e.u = id[dsu2.find(e.u)];e.v=id[dsu2.find(e.v)];
			if(e.l<=l && e.r>=r){
				if(!dsu1.join(e.u,e.v)){
					e.l=1e9;
					e.r=-1e9;
				}
			}
		}
		int m = (l+r)/2;
		solve(l,m,es,cnt,cost);
		solve(m,r,es,cnt,cost);
	}
	vector<ll> run(){
		int m = edgeset.size();
		q++;
		for(int i=0;i<m;i++){
			int u = get<0>(edgeset[i]);
			int v = get<1>(edgeset[i]);
			ll w = get<2>(edgeset[i]);
			int l = prev[i];
			Eran.push_back(edge(l,q,u,v,w));
		}
		sort(Eran.begin(),Eran.end());
		ans.resize(q);
		solve(0,q,Eran,realn,0);
		return ans;
	}
};


int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;
    cin>>n>>m>>q;
	vector<tuple<int,int,ll> > ogE(m);	
	for(int i=0;i<m;i++){
		int a,b;ll w;cin>>a>>b>>w;
		a--;b--;
		ogE[i] = {a,b,w};
	}
	DMST dmst(ogE,n);
	for(int i=0;i<q;i++){
		int k,w;cin>>k>>w;
		k--;
		dmst.update(k,w);
	}
	vector<ll> ans = dmst.run();
	for(int i=1;i<ans.size();i++) cout<<ans[i]<<"\n";
    return 0;
}
