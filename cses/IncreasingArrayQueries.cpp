#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct SEG{
	struct node{
		ll len = 1;
		ll sum = 0;
		ll tag = -1;
		void st(ll v){
			if(v==-1) return ;
			sum = v*len;
			tag = v;
		}
	};
	vector<node> arr;
	void init(int n){
		arr.resize(4*n);
	}
	void push(int arri){
		if(2*arri>=arr.size()) return;
		ll stt = arr[arri].tag;
		arr[2*arri].st(stt);
		arr[2*arri+1].st(stt);
	}
	void modify(int l,int r,int L,int R,int arri,ll v){
		push(arri);		
		if(l==L && r==R){arr[arri].st(v);return ;}
		int M =(R+L)/2;
		if(r<=M) modify(l,r,L,M,2*arri,v);
		else if(l>=M) modify(l,r,M,R,2*arri+1,v);
		else {modify(l,M,L,M,2*arri,v);modify(M,r,M,R,2*arri+1,v);}
		arr[arri].sum = arr[2*arri].sum+arr[2*arri+1].sum;
		ll sst = arr[arri].tag;
		arr[arri].st(sst);
	}
	ll query(int l,int r,int L,int R,int arri){
		push(arri);
		if(l==L && r==R) {return arr[arri].sum;};
		int M = (R+L)/2;
		if(r<=M) return query(l,r,L,M,2*arri);
		if(l>=M) return query(l,r,M,R,2*arri+1);
		return query(l,M,L,M,2*arri)+query(M,r,M,R,2*arri+1);
	}
	void built(int l,int r,int arri){
		arr[arri].len =  r-l;
		if(r-l==1) return;
		built(l,(r+l)/2,2*arri);
		built((r+l)/2,r,2*arri+1);
	}
} seg;

struct qe{
	int l;
	int r;
	int t;
	ll ans;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	seg.init(n);
	seg.built(1,n+1,1);
	qe query[q];
	int arr[n+1] = {0};
	ll sum[n+1] =  {0};
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i] = sum[i-1]+arr[i];
	}
	for(int i  = 0;i<q;i++) {
		cin>>query[i].l>>query[i].r;
		query[i].t = i;
	}
	sort(query,query+q,[](const qe &a,const qe &b){return a.l>b.l;});
	int cur = n;
	seg.modify(n,n+1,1,n+1,1,arr[n]);
	for(int i=0;i<q;i++){
		while(cur>query[i].l){
			cur--;	
			int l = cur;int r = n+1;
			while(r-l>1){
				int m = (r+l)/2;
				if(seg.query(m,m+1,1,n+1,1)<arr[cur]) l = m;
				else r = m;
			}
			seg.modify(cur,r,1,n+1,1,arr[cur]);
		}
		query[i].ans = seg.query(query[i].l,query[i].r+1,1,n+1,1)-sum[query[i].r]+sum[query[i].l-1];
	}
	sort(query,query+q,[](qe a,qe b){return a.t<b.t;});
	for(int i=0;i<q;i++){
		cout<<query[i].ans<<"\n";
	}
	return 0;
}
