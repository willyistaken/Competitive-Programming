#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
vector<int> initstuff;
struct SEG{
	struct node{
		ll sum = 0;
		ll len = 1;
		ll at = 0;
		ll pt = 0;
		void add(ll v){
			sum+=v*len;
			at+=v;
		}
		void poly(ll v){
			sum+=v* (((len*len)+len)/2);
			pt+=v;
		}
	};
	vector<node> arr;
	void init(int s){
		arr.resize(4*s);
	}
	void push(int arri){
		if(2*arri+1>=arr.size()) return;
		arr[2*arri].add(arr[arri].at);
		arr[2*arri+1].add(arr[arri].at);
		arr[2*arri].poly(arr[arri].pt);
		ll from = arr[2*arri].len;
		arr[2*arri+1].add(arr[arri].pt*from);
		arr[2*arri+1].poly(arr[arri].pt);
		arr[arri].at = 0;
		arr[arri].pt = 0;
	}
	void addrange(int l,int r,int L,int R,int arri,ll v){
		push(arri);
		int M = (L+R)/2;
		if(l==L && r==R) {arr[arri].add(v);return;}
		if(r<=M) addrange(l,r,L,M,2*arri,v);
		else if(l>=M) addrange(l,r,M,R,2*arri+1,v);
		else addrange(l,M,L,M,2*arri,v),addrange(M,r,M,R,2*arri+1,v);	
		arr[arri].sum = arr[2*arri].sum+arr[2*arri+1].sum;
	}
	void modify(int l,int r,int L,int R,int arri,ll v){
		push(arri);
		int M = (L+R)/2;
		if(l==L && r==R) {arr[arri].poly(v);return;}
		if(r<=M) modify(l,r,L,M,2*arri,v);
		else if(l>=M) modify(l,r,M,R,2*arri+1,v);
		else {
			modify(l,M,L,M,2*arri,v);
			addrange(M,r,M,R,2*arri+1,v*(M-l));
			modify(M,r,M,R,2*arri+1,v);	
		}
		arr[arri].sum = arr[2*arri].sum+arr[2*arri+1].sum;
	}
	ll query(int l,int r,int L,int R,int arri){
		push(arri);
		if(l==L && r==R)  return arr[arri].sum;
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*arri);
		else if(l>=M) return query(l,r,M,R,2*arri+1);
		else return query(l,M,L,M,2*arri)+query(M,r,M,R,2*arri+1);	
	}
	void built(int l,int r,int arri){
		if(r-l==1) {
			arr[arri].sum = initstuff[l];
			return ;
		}
		int m = (l+r)/2;
		built(l,m,2*arri);
		built(m,r,2*arri+1);
		arr[arri].sum = arr[2*arri].sum+arr[2*arri+1].sum;
		arr[arri].len = arr[2*arri].len+arr[2*arri+1].len;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	initstuff.resize(n);	
	for(int i =0;i<n;i++) cin>>initstuff[i];
	SEG seg;
	seg.init(n);
	seg.built(0,n,1);
	while(q--){
		int type;cin>>type;
		int a,b;cin>>a>>b;
		a--;
		if(type==1){
			seg.modify(a,b,0,n,1,1);
		}else{
			cout<<seg.query(a,b,0,n,1)<<"\n";
		}
	}
	return 0;
}
