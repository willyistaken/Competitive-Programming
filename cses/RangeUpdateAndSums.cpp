#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct SEG{
	struct node{
		ll sum = 0;
		ll len = 0;
		ll at = 0;
		ll st = 0;
		void addv(ll v){
			if(!v) return;
			sum+=len*v;
			at+=v;
		}
		void setv(ll v){
			if(!v) return;
			sum = len*v;
			at = 0;
			st = v;
		}
		void remake(){
			ll att = at;
			ll stt = st;
			at = 0;st = 0;		
			setv(stt);
			addv(att);
		}
	};
	vector<node> arr;
	void init(int n){
		arr.resize(5*n);
	}
	void push(int arri){
		if(2*arri>=arr.size()) return ;
		arr[2*arri].setv(arr[arri].st);
		arr[2*arri+1].setv(arr[arri].st);
		arr[2*arri].addv(arr[arri].at);
		arr[2*arri+1].addv(arr[arri].at);
		arr[arri].st=0;arr[arri].at = 0;
		arr[arri].remake();
	}
	void addr(int l,int r,int L,int R,int arri,ll v){
		push(arri);
		if(l==L && r==R) {arr[arri].addv(v);return ;};
		int M = (L+R)/2;
		if(r<=M) addr(l,r,L,M,2*arri,v);
		else if(l>=M) addr(l,r,M,R,2*arri+1,v);
		else {addr(l,M,L,M,2*arri,v);addr(M,r,M,R,2*arri+1,v);}
		arr[arri].sum = arr[2*arri].sum+arr[2*arri+1].sum;
		arr[arri].remake();
	}
	void setr(int l,int r,int L,int R,int arri,ll v){
		push(arri);
		if(l==L && r==R) {arr[arri].setv(v);return ;};
		int M = (L+R)/2;
		if(r<=M) setr(l,r,L,M,2*arri,v);
		else if(l>=M) setr(l,r,M,R,2*arri+1,v);
		else {setr(l,M,L,M,2*arri,v);setr(M,r,M,R,2*arri+1,v);}
		arr[arri].sum = arr[2*arri].sum+arr[2*arri+1].sum;
		arr[arri].remake();
	}
	ll query(int l,int r,int L,int R,int arri){
		push(arri);
		if(l==L && r==R) return arr[arri].sum;
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*arri);
		if(l>=M) return query(l,r,M,R,2*arri+1);
		return query(l,M,L,M,2*arri)+query(M,r,M,R,2*arri+1);
	}
	void built(int l,int r,int arri){
		arr[arri].len = r-l;	
		if(r-l==1) return;
		int m =(r+l)/2;
		built(l,m,2*arri);
		built(m,r,2*arri+1);
	}
} seg;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	seg.init(n);
	seg.built(0,n,1);
	for(int i=0;i<n;i++){
		int a;cin>>a;
		seg.addr(i,i+1,0,n,1,a);
	}
	while(q--){
		int t;cin>>t;
		if(t==1){
			int a,b,x;cin>>a>>b>>x;
			a--;
			seg.addr(a,b,0,n,1,x);
		}else if(t==2){
			int a,b,x;cin>>a>>b>>x;
			a--;
			seg.setr(a,b,0,n,1,x);
		}else{
			int a,b;cin>>a>>b;
			a--;
			cout<<seg.query(a,b,0,n,1)<<"\n";
		}
	}
	return 0;
}
