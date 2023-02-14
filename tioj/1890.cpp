#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int N  = 500005;
int p[N];
int sz[N];

struct dsu{
	int m;
	stack<pair<int*,int> > psz;
	stack<pair<int*,int> > pp;
	void init(int n){
		m=n;
		while(psz.size()) psz.pop();
		while(psz.size()) psz.pop();
		for(int i=0;i<n;i++){
			p[i]=i;
			sz[i] = 1;
		}
	}
	int query(int a){
		while(a!=p[a]) a = p[a];
		return a;
	}
	bool merge(int a,int b){
		a = query(a);
		b = query(b);
		if(a==b) {
			return 0;
		}
		if(sz[a]<sz[b]) swap(a,b);
		psz.push(make_pair(&sz[a],sz[a]));
		pp.push(make_pair(&p[b],p[b]));
		m--;
		sz[a]+=sz[b];
		p[b]=a;
		return 1;
	}

	void undo(){
		auto fp = pp.top();
		auto fs = psz.top();
		pp.pop();
		psz.pop();
		*fp.first = fp.second;
		*fs.first = fs.second;
		m++;
	}
} s;

struct event{
	int a;
	int b;
};

struct seg{
	vector<vector<event>> arr;
	int T;
	void init(int t){
		T = t;
		arr.resize(4*T);
		for(int i=0;i<4*T;i++) arr[i].clear();
	}

	void add(int l,int r,int L,int R,int ind,event k){
		if(l==L && r==R){
			arr[ind].push_back(k);
			return ;
		}
		int M = (L+R)/2;
		if(r<=M) add(l,r,L,M,2*ind,k);
		else if(l>=M) add(l,r,M,R,2*ind+1,k);
		else{
			add(l,M,L,M,2*ind,k);
			add(M,r,M,R,2*ind+1,k);
		}
	}
	void travel(int l,int r,int ind){
		int cnt=  0;
		for(auto e : arr[ind]){
			if(s.merge(e.a,e.b)){
				cnt++;
			}
		}
		if(r-l==1) {
			cout<<s.m<<"\n";
		}
		else{
			int m = (l+r)/2;
			travel(l,m,2*ind);
			travel(m,r,2*ind+1);
		}
		for(int i=0;i<cnt;i++){
			s.undo();
		}
	}
} SEG;

ll mk(int l,int r){
	return 1LL*r*N+l;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m,q;cin>>n>>m>>q;
		s.init(n);
		SEG.init(q);
		unordered_map<ll,int> cnt;
		unordered_map<ll,int> ff;
		for(int i=0;i<m;i++){
			int l,r;cin>>l>>r;
			if(r<l) swap(l,r);
			if(cnt[mk(l,r)]==0) ff[mk(l,r)] = 0;
			cnt[mk(l,r)]++;
		}
		for(int i=0;i<q;i++){
			char a;cin>>a;
			int l,r;cin>>l>>r;
			if(r<l) swap(l,r);
			if(a=='N'){
				if(cnt[mk(l,r)]==0) ff[mk(l,r)] = i;
				cnt[mk(l,r)]++;
			}else{
				cnt[mk(l,r)]--;	
				if(cnt[mk(l,r)]==0){
					SEG.add(ff[mk(l,r)],i,0,q,1,{l,r});
				}
			}
		}
		for(auto pr : cnt){
			if(pr.second==0) continue;
			SEG.add(ff[pr.first],q,0,q,1,{(int)(pr.first%N),(int)(pr.first/N)});
		}
		SEG.travel(0,q,1);
	}
	return 0;
}

