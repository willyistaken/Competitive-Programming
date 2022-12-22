#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct node{
	ll v1 = 1e12;
	ll v2 = 1e12;
};

node combine(node a,node b){
	node r;
	r.v1 = min(a.v1,b.v1);
	r.v2 = min(a.v2,b.v2);
	return r;
}

struct SEG{
	vector<node> arr;
	void init(int n){
		arr.resize(4*n);
	}
	void modify(int ind,node v,int L,int R,int arri){
		if(L==ind && R-L==1){
			arr[arri]= v;
			return;
		}
		int M = (R+L)/2;
		if(ind<M) modify(ind,v,L,M,2*arri);
		if(ind>=M) modify(ind,v,M,R,2*arri+1);
		arr[arri] = combine(arr[2*arri],arr[2*arri+1]);
	}
	node query(int l,int r,int L,int R,int arri){
		if(l==r) {node a;return a;}
		if(l==L && r==R) return arr[arri];
		int M = (R+L)/2;
		if(r<=M) return query(l,r,L,M,2*arri);
		if(l>=M) return query(l,r,M,R,2*arri+1);
		return combine(query(l,M,L,M,2*arri),query(M,r,M,R,2*arri+1));
	}
} seg;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	seg.init(n);
	for(int i=0;i<n;i++){
		int v;cin>>v;
		node k;
		k.v1 = v-i;
		k.v2 = v+i;
		seg.modify(i,k,0,n,1);
	}
	while(q--){
		int t;cin>>t;
		if(t==1){
			int ind,a;cin>>ind>>a;
			ind--;
			node k;
			k.v1  = a-ind;
			k.v2 = a+ind;
			seg.modify(ind,k,0,n,1);
		}else{
			int ind;cin>>ind;
			ind--;
			cout<<min(seg.query(0,ind,0,n,1).v1+ind,seg.query(ind,n,0,n,1).v2-ind)<<"\n";
		}
	}
	return 0;
}
