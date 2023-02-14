#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
vector<int> og;
struct SEG{
	struct node{
		ll maxn = 0;
		ll sum = 0;
		ll stag = 0;
		ll atag = 0;
		ll len = 0;
		void set(ll k){
			atag = 0;
			stag = k;
			maxn = k;
			sum=len*k;
		}
		void add(ll k){
			atag+=k;
			maxn+=k;
			sum+=len*k;
		}
	};
	vector<node> arr;
	int n;
	void init(int s){
		arr.resize(4*s);
		n = s;
	}
	void push(int L,int R,int ind){
		if(R-L<=1) return ;
		if(arr[ind].stag){
			arr[2*ind].set(arr[ind].stag);
			arr[2*ind+1].set(arr[ind].stag);
		}
		if(arr[ind].atag){
			arr[2*ind].add(arr[ind].atag);
			arr[2*ind+1].add(arr[ind].atag);
		}
		arr[ind].stag=0;
		arr[ind].atag=0;
	}
	void range(int l,int r,int L,int R,int ind,ll v,bool type){
		push(L,R,ind);
		if(l==L && r==R){
			if(type) arr[ind].add(v);
			else arr[ind].set(v);
			return ;
		}else{
			int M = (L+R)/2;	
			if(r<=M) range(l,r,L,M,2*ind,v,type);		
			else if(l>=M) range(l,r,M,R,2*ind+1,v,type);
			else{
				range(l,M,L,M,2*ind,v,type);
				range(M,r,M,R,2*ind+1,v,type);
			}
			arr[ind].sum = arr[2*ind].sum+arr[2*ind+1].sum;
			arr[ind].maxn = max(arr[2*ind].maxn,arr[2*ind+1].maxn);
		}
	}
	ll sumquery(int l,int r,int L,int R,int ind){
		push(L,R,ind);
		if(l==L && r==R) return arr[ind].sum;
		int M = (L+R)/2;
		if(r<=M) return sumquery(l,r,L,M,2*ind);
		if(l>=M) return sumquery(l,r,M,R,2*ind+1);
		return sumquery(l,M,L,M,2*ind)+sumquery(M,r,M,R,2*ind+1);
	}
	ll maxquery(int l,int r,int L,int R,int ind){
		push(L,R,ind);
		if(l==L && r==R) return arr[ind].maxn;
		int M = (L+R)/2;
		if(r<=M) return maxquery(l,r,L,M,2*ind);
		if(l>=M) return maxquery(l,r,M,R,2*ind+1);
		return max(maxquery(l,M,L,M,2*ind),maxquery(M,r,M,R,2*ind+1));
	}
	void built(int l,int r,int ind){
		arr[ind].len = r-l;
		if(r-l<=1) {
			arr[ind].sum = og[l];
			arr[ind].maxn = og[l];
			return ;
		}
		int m = (l+r)/2;
		built(l,m,2*ind);
		built(m,r,2*ind+1);
		arr[ind].sum = arr[2*ind].sum+arr[2*ind+1].sum;
		arr[ind].maxn = max(arr[2*ind].maxn,arr[2*ind+1].maxn);
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;	
	og.resize(n);
	for(int i=0;i<n;i++) cin>>og[i];
	SEG seg;
	seg.init(n);
	seg.built(0,n,1);
	while(q--){
		int k;cin>>k;
		int l,r;cin>>l>>r;
		l--;
		if(k<=2){
			int x;cin>>x;
			seg.range(l,r,0,n,1,x,k-1);
		}else{
			if(k==3) cout<<seg.sumquery(l,r,0,n,1)<<"\n";
			else cout<<seg.maxquery(l,r,0,n,1)<<"\n";
		}
	}
	return 0;
}
