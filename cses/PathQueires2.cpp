#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
int sz[N];
int p[N];
int dep[N];
int c[N];
int hd[N];
int ord[N];
vector<int> side[N];
void dfs(int v,int f){
	sz[v]++;	
	p[v] = f;
	dep[v]=  dep[f]+1;
	int maxs = 0;
	for(auto i : side[v]){
		if(!sz[i]) {
			dfs(i,v);
			sz[v]+=sz[i];
			if(maxs<sz[i]){
				maxs = sz[i];
				c[v] = i;
			}
		}
	}
}
int t;
void decompose(int v,int h){
	if(v==0) return;
	hd[v]=  h;	
	ord[v]=++t;
	decompose(c[v],h);
	for(auto i : side[v]){
		if(i!=p[v] && i!=c[v]){
			decompose(i,i);
		}
	}
}
struct SEG{
	vector<int> arr;
	void init(int n){
		arr.resize(4*n,0);
	}
	void modify(int ind,int L,int R,int arri,int v){
		if(ind==L && R-L==1){arr[arri] = v;return ;}
		int M = (L+R)/2;
		if(ind<M) modify(ind,L,M,2*arri,v);
		else modify(ind,M,R,2*arri+1,v);
		arr[arri] = max(arr[2*arri],arr[2*arri+1]);
	}
	int query(int l,int r,int L,int R,int arri){
		if(l==L && r==R) return arr[arri];
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*arri);
		if(l>=M) return query(l,r,M,R,2*arri+1);
		return max(query(l,M,L,M,2*arri),query(M,r,M,R,2*arri+1));
	}
} seg;
int n,q;
int query(int a,int b){
	int ans = 0;
	while(hd[a]!=hd[b]){
		if(dep[hd[a]]>dep[hd[b]]){// not dep[a]>dep[b] ** important
			ans = max(ans,seg.query(ord[hd[a]],ord[a]+1,1,n+1,1));
			a = p[hd[a]];
		}else{
			ans = max(ans,seg.query(ord[hd[b]],ord[b]+1,1,n+1,1));
			b = p[hd[b]];
		}
	}
	if(dep[a]>dep[b]) swap(a,b);
	ans = max(ans,seg.query(ord[a],ord[b]+1,1,n+1,1));
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	int w[n+1];		
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(1,1);
	decompose(1,1);
	seg.init(n);
	for(int i=1;i<=n;i++){
		seg.modify(ord[i],1,n+1,1,w[i]);
	}
	while(q--){
		int ty;cin>>ty;
		if(ty==1){
			int v,x;cin>>v>>x;
			seg.modify(ord[v],1,n+1,1,x);
		}else{
			int a,b;cin>>a>>b;	
			cout<<query(a,b)<<" ";
		}
	}
	cout<<"\n";
	return 0;
}
