#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct node{
	ll ans = 0;
	ll sum = 0;
};

node combine(node a,node b){
	node r;
	r.ans = max(a.ans,a.sum+b.ans);
	r.sum = a.sum+b.sum;
	return r;
}

struct SEG{
	vector<node> arr;
	void init(int n){
		arr.resize(4*n);
	}
	void modify(int ind,int v,int L,int R,int arri){
		if(L==ind && R-L==1){
			arr[arri].ans=v;
			arr[arri].sum=v;
			return ;
		}
		int M = (L+R)/2;
		if(ind<M) modify(ind,v,L,M,2*arri);
		if(ind>=M) modify(ind,v,M,R,2*arri+1);
		arr[arri] = combine(arr[2*arri],arr[2*arri+1]);
	}
	node query(int l,int r,int L,int R,int arri){
		if(l==L && r==R) return arr[arri];
		int M = (L+R)/2;
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
		int a;cin>>a;
		seg.modify(i,a,0,n,1);
	}
	while(q--){
		int t;cin>>t;
		if(t==1){
			int k,v;cin>>k>>v;
			k--;
			seg.modify(k,v,0,n,1);
		}else{
			int a,b;cin>>a>>b;
			a--;
			cout<<max(0LL,seg.query(a,b,0,n,1).ans)<<"\n";
		}
	}

	return 0;
}
