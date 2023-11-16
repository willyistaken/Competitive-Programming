#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds
struct SegTree{
	struct node{
		int Minn = 0;
		int SMinn = (1e18);
		int maxtag= -1;
		int addtag = 0;
		void add(int v){
			Minn+=v;
			if(SMinn<1e18) SMinn+=v;
			if(maxtag!=-1) maxtag+=v;
			addtag +=v;		
		}
		void chmax(int v){
			if(v<=Minn) return;
			//addtag = max(v,addtag);
			maxtag = max(maxtag,v);
			Minn = v;

		}
	};
	node merge(node a,node b){
		node re;
		re.Minn = min(a.Minn,b.Minn);
		if(a.Minn == b.Minn){
			re.SMinn = min(a.SMinn,b.SMinn);
		}else if(a.Minn<b.Minn){
			re.SMinn = min(a.SMinn,b.Minn);
		}else{
			re.SMinn = min(b.SMinn,a.Minn);
		}
		return re;
	}
	vector<node> arr;
	int n;
	void init(int _n){
		n = _n;
		arr.resize(4*n)	;
	}
	void push(int ind){
		if(arr[ind].addtag){
			if(2*ind<4*n) arr[2*ind].add(arr[ind].addtag);
			if(2*ind+1<4*n) arr[2*ind+1].add(arr[ind].addtag);
		}
		arr[ind].addtag=0;
		if(arr[ind].maxtag!=-1){
			if(2*ind<4*n) arr[2*ind].chmax(arr[ind].maxtag);
			if(2*ind+1<4*n) arr[2*ind+1].chmax(arr[ind].maxtag);
		}
		arr[ind].maxtag=-1;
	}
	void built(int ind,int L,int R){
		if(L==R) return;
		int M = (L+R)/2;
		built(2*ind,L,M);
		built(2*ind,M+1,R);
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	void Radd(int ind,int l,int r,int L,int R,int v){
		//cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
		push(ind);
		if(L==l && r==R){
			arr[ind].add(v);
			return;
		}
		int M = (L+R)/2;
		if(r<=M) Radd(2*ind,l,r,L,M,v);
		else if(l>M) Radd(2*ind+1,l,r,M+1,R,v);
		else{
			Radd(2*ind,l,M,L,M,v);
			Radd(2*ind+1,M+1,r,M+1,R,v);
		}
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	void Rchmax(int ind,int l,int r,int L,int R,int v){
		//cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
		push(ind);
		if(l==L && r==R && v<arr[ind].SMinn){
			assert(arr[ind].addtag==0);
			arr[ind].chmax(v);
			return;
		}
		int M = (L+R)/2;
		if(r<=M) Rchmax(2*ind,l,r,L,M,v);
		else if(l>M) Rchmax(2*ind+1,l,r,M+1,R,v);
		else{
			Rchmax(2*ind,l,M,L,M,v);
			Rchmax(2*ind+1,M+1,r,M+1,R,v);
		}
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	int query(int ind,int x,int L,int R){
		push(ind);
		if(L==R) return arr[ind].Minn;
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
		int M = (L+R)/2;
		if(x<=M) return query(2*ind,x,L,M);
		else return query(2*ind+1,x,M+1,R);
	}
} seg;

struct bit{
	vector<ll> arr;
	int n;
	void init(int _n){
		n = _n;
		arr.resize(n+1);
	}
	void add(int ind,ll v){
		while(ind<=n) {
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		int ans = 0;	
		while(ind){
			ans+=arr[ind];
			ind-=(ind&-ind);
		}
		return ans;
	}
};
bit sum;



vector<int> ans;
vector<pair<int,int> > Q;
vector<tuple<int,int,int,int> > T;

void do_stuff(int l,int r,int v){
	for(int i=l;i<=r;i++){
		sum.add(get<0>(T[i]),v*get<3>(T[i]));	
		sum.add(get<1>(T[i])+1,-v*get<3>(T[i]));	
	}
}


void total_bs(vector<int> &q,int l,int r){
	if(l==r){
		for(auto i : q) ans[i]=get<2>(T[l]);
		return;
	}
	int m = (l+r)/2;
	do_stuff(l,m,1);
	vector<int> L;
	vector<int> R;
	for(auto i : q){
		if(sum.query(Q[i].first)<Q[i].second) R.push_back(i);
		else L.push_back(i);
	}
	vector<int>().swap(q);
	total_bs(R,m+1,r);
	do_stuff(l,m,-1);
	total_bs(L,l,m);
}


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	seg.init(n);
	seg.built(1,1,n);
	int cnt = 0;
	bit inpeople;
	inpeople.init(n);
	sum.init(n);
	vector<int> ask;
	while(q--){
		int t;cin>>t;
		if(t==1){
			int l,r,c,k;cin>>l>>r>>c>>k;
			seg.Radd(1,l,r,1,n,k);
			inpeople.add(l,k);
			inpeople.add(r+1,-k);
			T.push_back({l,r,c,k});
		}
		if(t==2){
			int l,r,k;cin>>l>>r>>k;
			seg.Radd(1,l,r,1,n,-k);
			seg.Rchmax(1,l,r,1,n,0);
		}
		if(t==3){
			int a,b;cin>>a>>b;	
			int g = seg.query(1,a,1,n);
			ans.push_back(0);
			if(g>=b){
				int k = inpeople.query(a)-g+b;
				Q.push_back({a,k});
				ask.push_back(cnt);
			}else{
				Q.push_back({0,0});
			}
			cnt++;
		}
	}
	
	total_bs(ask,0,T.size()-1);
	for(auto i : ans) cout<<i<<"\n";
	return 0;
}

// segment tree beats + parellal binary search

