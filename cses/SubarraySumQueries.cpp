#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct node{
	ll ans = 0;
	ll lmax = 0;
	ll rmax = 0;
	ll sum  = 0;
};
node combine(node a,node b){
	node r;
	r.ans = max(a.ans,b.ans);
	r.ans = max(r.ans,a.rmax+b.lmax);
	r.rmax = max(b.rmax,b.sum+a.rmax);
	r.lmax = max(a.lmax,b.lmax+a.sum);
	r.sum = a.sum+b.sum;
	return r;
}
struct SEG{
	vector<node> arr;	
	void init(int n){
		arr.resize(4*n);
	}
	void modify(int ind,ll v,int L,int R,int arri){
		if(L==ind && R-L==1){
			arr[arri] = {v,v,v,v};
			return ;
		}
		int M = (R+L)/2;
		if(ind<M) modify(ind,v,L,M,2*arri);
		if(ind>=M) modify(ind,v,M,R,2*arri+1);
		arr[arri] = combine(arr[2*arri],arr[2*arri+1]);
	}
	ll query(){
		return max(0LL,arr[1].ans);
	}
} seg;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;	
	seg.init(n);
	for(int i=0;i<n;i++){
		int v;cin>>v;
		seg.modify(i,v,0,n,1);
	}
	while(m--){
		int k,x;cin>>k>>x;
		k--;
		seg.modify(k,x,0,n,1);
		cout<<seg.query()<<"\n";
	}

	return 0;
}
