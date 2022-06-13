#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	ll ans;
	ll lmax;
	ll rmax;
	ll sum;
};
node combine(const node &a,const node &b){
	node r;
	r.sum = a.sum+b.sum;
	r.lmax = max(a.lmax,a.sum+b.lmax);
	r.rmax = max(b.rmax,b.sum+a.rmax);
	r.ans =  max({a.ans,b.ans,a.rmax+b.lmax});
	return r;
}
int n;
void change(int ind,node s,vector<node> &segtree){
	ind+=n;
	segtree[ind]=s;
	ind>>=1;
	while(ind){
		segtree[ind] = combine(segtree[2*ind],segtree[2*ind +1]);
		ind>>=1;
	}
}

node query(int l,int r,vector<node> &segtree){
	l+=n;
	r+=n;
	node rr={(long long)-1e15,(long long)-1e15,(long long)-1e15,0LL};
	node lr={(long long)-1e15,(long long)-1e15,(long long)-1e15,0LL};
	while(l<r){
		if(l%2) lr = combine(lr,segtree[l++]);
		if(r%2) rr = combine(segtree[--r],rr);
		l>>=1;
		r>>=1;
	}
	return combine(lr,rr);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	int q;cin>>q;
	vector<node> segtree(2*n,{0,0,0,0});
	for(int i=0;i<n;i++){
		int a;cin>>a;
		change(i,{a,a,a,a},segtree);
	}
	for(;q;q--){
		int l,r;cin>>l>>r;
		l-=1;
		cout<<max(0LL,query(l,r,segtree).ans)<<endl;
	}
	return 0;
}
