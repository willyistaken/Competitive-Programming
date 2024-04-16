#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct seg{
	int n;
	struct node{
		ll sum=0;
		ll tag=0;
		ll len=1;
		void add(ll x){
			sum+=x*len;
			tag+=x;
		}
	};
	vector<node> arr;
	void init(int _n){
		n = _n;
		arr.resize(4*n);
	}
	node merge(node a,node b){
		node r;
		r.sum = a.sum+b.sum;
		r.len = a.len+b.len;
		return r;
	}
	void push(int ind){
		if(arr[ind].tag){
			arr[2*ind].add(arr[ind].tag);
			arr[2*ind+1].add(arr[ind].tag);
			arr[ind].tag=0;
		}
	}
	void built(int l,int r,int ind){
		if(l==r) return;
		int m = (l+r)/2;
		built(l,m,2*ind);
		built(m+1,r,2*ind+1);
		arr[ind]=merge(arr[2*ind],arr[2*ind+1]);
	}
	void modify(int l,int r,ll x,int L,int R,int ind){
		if(l==L && r==R){
			arr[ind].add(x);
			return;
		}
		push(ind);
		int M = (L+R)/2;
		if(r<=M) modify(l,r,x,L,M,2*ind);
		else if(l>M) modify(l,r,x,M+1,R,2*ind+1);
		else{
			modify(l,M,x,L,M,2*ind);
			modify(M+1,r,x,M+1,R,2*ind+1);
		}
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	ll query(int l,int r,int L,int R,int ind){
		if(l==L && r==R) return arr[ind].sum;
		push(ind);
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		if(l>M) return query(l,r,M+1,R,2*ind+1);
		return query(l,M,L,M,2*ind)+query(M+1,r,M+1,R,2*ind+1);
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	ll D;cin>>D;
	vector<ll> arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i];
	vector<ll> sum(n+1,0);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
	int q;cin>>q;
	vector<ll> ans(q,0);
	vector<vector<pair<int,int> > > query(n+1);
	for(int i=0;i<q;i++){
		int l,r;cin>>l>>r;
		query[r].push_back({l,i});
	}
	seg s;
	s.init(n);
	s.built(1,n,1);
	stack<int> stk;
	for(int r=1;r<=n;r++){
		ll cc = arr[r];
		while(stk.size()){
			if(s.query(stk.top(),stk.top(),1,n,1)>=cc){
				int cur = stk.top();
				stk.pop();
				int l = (stk.size()==0)?(0):(stk.top());
				ll f =(s.query(cur,cur,1,n,1)-cc+D-1)/D;
				s.modify(l+1,cur,-f*D,1,n,1);
				cc = s.query(l+1,l+1,1,n,1);
			}else break;
		}
		stk.push(r);
		s.modify(r,r,arr[r],1,n,1);
		/*
		for(int i=1;i<=n;i++) cout<<s.query(i,i,1,n,1)<<" ";
		cout<<"\n";
		*/
		for(auto g : query[r]){
			if(s.query(g.first,g.first,1,n,1)<0) ans[g.second]=-1;
			else ans[g.second] = (sum[r]-sum[g.first-1]-s.query(g.first,r,1,n,1))/D;
		}
	}
	for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
	return 0;
}


