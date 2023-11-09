#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 505;
int P[N];

int n,m;
void reset(){
	for(int i=1;i<=n;i++) P[i]=i;
}

int query(int x){
	if(P[x]==x) return x;
	return P[x]=query(P[x]);
}
struct edge{
	int a,b,w;
	edge(int _a,int _b,int _c){
		a = _a;
		b = _b;
		w = _c;
	}
};
vector<edge> ed;
void solve(int x,int g){
	reset();
	int l = g-1;int r = g;
	ll ans = 0;
	int cnt = 0;
	while(cnt!=n-1){
		if(l<0 || r>=m)	{
			if(l<0)	{
				if(query(ed[r].a)!=query(ed[r].b)){
					ans+=abs(x-ed[r].w);
					cnt++;
					P[query(ed[r].a)]=query(ed[r].b);
				}
				r++;
			}else{
				if(query(ed[l].a)!=query(ed[l].b)){
					ans+=abs(x-ed[l].w);
					cnt++;
					P[query(ed[l].a)]=query(ed[l].b);
				}
				--l;
			}
		}else{
			if(abs(x-ed[r].w)>abs(x-ed[l].w)){
				if(query(ed[l].a)!=query(ed[l].b)){
					ans+=abs(x-ed[l].w);
					cnt++;
					P[query(ed[l].a)]=query(ed[l].b);
				}
				--l;
			}else{
				if(query(ed[r].a)!=query(ed[r].b)){
					ans+=abs(x-ed[r].w);
					cnt++;
					P[query(ed[r].a)]=query(ed[r].b);
				}
				r++;
			}
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		ed.push_back(edge(a,b,c));
	}
	sort(ed.begin(),ed.end(),[](const edge &a,const edge &b){return a.w<b.w;});
	int q;cin>>q;
	while(q--){
		int x;cin>>x;
		int l = -1;
		int r = m;
		while(r-l>1){
			int mid = (l+r)/2;
			if(ed[mid].w<x) l=mid;
			else r=mid;
		}
		solve(x,r);
	}
	return 0;
}
