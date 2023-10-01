#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,m,q;
const int N = 1e5+5;
int sz[N];
int hd[N];
int dep[N];
int p[N];
vector<int> side[N];
int t;
void dfs_sz(int cur){
	sz[cur]=1;
	for(int i=0;i<side[cur].size();i++){
		if(!sz[side[cur][i]]){
			dfs_sz(side[cur][i]);
			sz[cur]+=sz[side[cur][i]];
			if(sz[side[cur][i]]>sz[side[cur][0]]){
				swap(side[cur][i],side[cur][0]);
			}
		}
	}
}
void dfs_hd(int cur){
	dep[cur]=++t;
	for(int i=0;i<side[cur].size();i++){
		if(!hd[side[cur][i]]){
			p[side[cur][i]] = cur;
			if(i==0) hd[side[cur][i]] = hd[cur];
			else hd[side[cur][i]] = side[cur][i];
			dfs_hd(side[cur][i]);
		}
	}
}

map<int,int> s;
vector<int> bit;
void modify(int ind,int v){
	if(ind==0) return;
	while(ind<=m){
		bit[ind]+=v;
		ind+=(ind&-ind);
	}
}
int Query(int ind){
	int ans = 0;
	while(ind){
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}
void setx(int l,int r,int x){
	auto lit = s.upper_bound(l);
	lit = prev(lit);
	int fl = lit->first;
	int fv = lit->second;
	int pv = 0;
	while(lit->first<=r){
		pv = lit->second;
		modify(lit->second,-(next(lit)->first-lit->first));	
		auto k = lit;
		++lit;
		s.erase(k);
	}
	modify(x,r-l+1);
	modify(fv,l-fl);
	if(lit->first!=r+1){
		s[r+1] = pv;
		modify(pv,lit->first-(r+1));
	}
	s[fl] = fv;
	s[l] = x;
}

void cover(int a,int b,int x){
	while(a!=b){
		if(hd[a]==hd[b]){
			int l = dep[a];
			int r = dep[b];
			if(l>r) swap(l,r);
			setx(l,r,x);
			a=b;
		}else{
			if(dep[hd[a]]>dep[hd[b]]) swap(a,b);
			int l = dep[hd[b]];
			int r = dep[b];
			setx(l,r,x);
			b = p[hd[b]];
		}
	}
	setx(dep[a],dep[b],x);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	bit.resize(m+1);
	s[1]=0;
	s[n+1]=0;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	p[1]=1;
	hd[1]=1;
	dfs_sz(1);
	dfs_hd(1);
	vector<int> arr(m+1);
	for(int i=1;i<=m;i++) cin>>arr[i];
	vector<pair<int,int>> query(q);
	vector<int> ord(q);
	vector<int> ans(q);
	for(int i=0;i<q;i++){
		cin>>query[i].first>>query[i].second;
		ord[i]=i;
	}
	sort(ord.begin(),ord.end(),[&](const int a,const int b){return query[a].second<query[b].second;});
	int qhead = 0;
	for(int r=1;r<=m;r++){
		if(r>1){
			int u = arr[r-1];
			int v = arr[r];
			cover(u,v,r);
		}else{
			setx(dep[arr[r]],dep[arr[r]],1)	;
		}
		while(qhead<q && query[ord[qhead]].second==r){
			ans[ord[qhead]]=Query(m)-Query(query[ord[qhead]].first);
			qhead++;
		}
	}
	for(int i=0;i<q;i++){
		cout<<max(1,ans[i])<<"\n";
	}
	return 0;
}
