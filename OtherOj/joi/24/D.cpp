#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



bool solve(vector<pair<int,int> > arr){
	int n = arr.size();
	sort(arr.begin(),arr.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.second<b.second;});
	int maxA = -1;
	for(int i=0;i<n;i++){
		bool ok = 0;
		if(i+1<n){
			if(arr[i+1].second<=arr[i].first) ok=1;
		}
		if(maxA>arr[i].second) ok=1;
		maxA = max(maxA,arr[i].first);
		if(!ok) return 0;
	}
	return 1;
}

struct seg1{
	int n;
	bool g;
	struct node{
		int v;
		bool f=0;
		void tag(int c){
			v = c;
			f=1;
		}
	};
	vector<node> arr;	
	void init(int _n,bool k){
		n = _n;
		g = k;
		int f = (g)?(-1e9):(1e9);
		arr.resize(4*n);
		node c;
		c.v = f;
		fill(arr.begin(),arr.end(),c);
	}
	node merge(node a,node b){
		node c;
		c.v = (g)?(max(a.v,b.v)):(min(a.v,b.v));
		return c;
	}
	void push(int ind){
		if(arr[ind].f){
			arr[ind].f=0;
			arr[2*ind].tag(arr[ind].v);
			arr[2*ind+1].tag(arr[ind].v);
		}
	}
	void modify(int l,int r,int v,int L,int R,int ind){
		if(l==L && r==R) {
			arr[ind].tag(v);
			return;
		}
		int M = (L+R)/2;
		if(r<=M) modify(l,r,v,L,M,2*ind);
		else if(l>M) modify(l,r,v,M+1,R,2*ind+1);
		else{
			modify(l,M,v,L,M,2*ind);
			modify(M+1,r,v,M+1,R,2*ind+1);
		}
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	node query(int l,int r,int L,int R,int ind){
		if(l==L && r==R){
			return arr[ind];
		}
		push(ind);
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		if(l>M) return query(l,r,M+1,R,2*ind+1);
		return merge(query(l,M,L,M,2*ind),query(M+1,r,M+1,R,2*ind+1));
	}
};


struct BIT{
	int n;	
	vector<int> arr;
	void init(int _n){
		n = _n;	
		arr.resize(n+1,0);
	}
	void add(int ind,int v){
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		int s=0;
		while(ind){
			s+=arr[ind];
			ind-=(ind&-ind);
		}
		return s;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pair<int,int> > arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i].second;
	for(int i=1;i<=n;i++) cin>>arr[i].first;
	vector<pair<int,int> > range(n+1);
	seg1 chl;
	chl.init(2*n,1);
	seg1 chr;
	chr.init(2*n,0);
	for(int i=1;i<=n;i++){
		range[i].first = chl.query(arr[i].first,arr[i].second,1,2*n,1).v;
		chl.modify(arr[i].first,arr[i].second,i,1,2*n,1);
	}
	for(int i=n;i>=1;i--){
		range[i].second = chr.query(arr[i].first,arr[i].second,1,2*n,1).v;
		chr.modify(arr[i].first,arr[i].second,i,1,2*n,1);
	}
	vector<vector<int> > remove(n+2);
	vector<vector<int> > add(n+2);
	for(int i=1;i<=n;i++){
		range[i].first = max(0,range[i].first);
		range[i].second = min(range[i].second,n+1);
		remove[range[i].second].push_back(i);
		add[i].push_back(i);
	}
	int q;cin>>q;			
	int ans[q];
	pair<int,int> Q[q];
	vector<int> ord(q);
	for(int i=0;i<q;i++){
		cin>>Q[i].first>>Q[i].second;
		ord[i]=i;
	}
	BIT bit;
	bit.init(n);
	sort(ord.begin(),ord.end(),[&](const int a,const int b){return Q[a].second<Q[b].second;});
	int head = 0;
	for(int r=1;r<=n;r++){
		for(auto i : remove[r])	{
			bit.add(range[i].first+1,-1);
			bit.add(i+1,1);
		}
		for(auto i : add[r]){
			bit.add(range[i].first+1,1);
			bit.add(i+1,-1);
		}
		while(head<q && Q[ord[head]].second==r){
			ans[ord[head]] = (bit.query(Q[ord[head]].first)==0);
			head++;
		}
	}
	for(int i=0;i<q;i++){
		if(ans[i]) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
