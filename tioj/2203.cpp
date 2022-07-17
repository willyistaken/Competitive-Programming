#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int invtwo = 500000004;
int n,Q;

ll MA(const ll a,const ll b){
	return ((a+b > MOD) ? a+b-MOD:a+b);
}
ll MM(const ll a,const ll b){
	return (a*b)%MOD;
}
struct node{
	ll m=0;
	ll v=0;
	ll v2=0;
	ll mv=0;
	ll mv2=0;
	ll vtag=0;
	ll mtag=0;
	int len=1;
	void addv(ll u){
		v2 = MA(v2 , MM(v,MM(2,u)));	
		v2 = MA(v2,MM(len,MM(u,u)));
		mv2 = MA(mv2,MM(mv,MM(2,u)));
		mv2 = MA(mv2,MM(m,MM(u,u)));
		mv = MA(mv,MM(u,m));
		v=MA(v,MM(len,u));
		vtag=MA(vtag,u);
	}

	void addm(ll u){
		m = MA(m, MM(len,u) );
		mv = MA(mv, MM(u,v) );
		mv2 = MA(mv2, MM(u,v2) );
		mtag = MA(mtag,u);
	}
	void merge(node a,node b){
		len = a.len+b.len;
		v = MA(a.v,b.v);
		m = MA(a.m,b.m);
		mv = MA(a.mv,b.mv);
		v2 = MA(a.v2,b.v2);
		mv2 = MA(a.mv2,b.mv2);
		ll ogmtag=mtag;
		ll ogvtag=vtag;
		addm(mtag);
		addv(vtag);
		mtag=ogmtag;
		vtag=ogvtag;
	}
};

struct myseg{
	vector<node> arr;
	void init(){
		cin>>n>>Q;
		arr.resize(2*n);
		for(int i=0;i<n;i++){
			ll k;cin>>k;
			arr[i+n].addm(k);
		}
		for(int i=0;i<n;i++){
			ll k;cin>>k;
			arr[i+n].addv(k);
		}
		for(int i=n-1;i>=1;i--){
			arr[i].merge(arr[2*i],arr[2*i+1]);
		}
	}
	void pull(int ind){
		if(ind<=1) return;
		pull(ind>>1);
		if(arr[ind>>1].mtag){
			arr[ind].addm(arr[ind>>1].mtag);
			arr[ind^1].addm(arr[ind>>1].mtag);
			arr[ind>>1].mtag=0;
		}
		if(arr[ind>>1].vtag){
			arr[ind].addv(arr[ind>>1].vtag);
			arr[ind^1].addv(arr[ind>>1].vtag);
			arr[ind>>1].vtag=0;
		}
	}
	void push(int ind){
		ind>>=1;
		while(ind){
			arr[ind].merge(arr[2*ind],arr[2*ind+1]);
			ind>>=1;
		}
	}
	void raddm(int l,int r,ll u){
		l+=n;r+=n;
		pull(l);pull(r-1);
		int tl=l;int tr=r;
		while(l<r){
			if(l%2) arr[l++].addm(u);
			if(r%2) arr[--r].addm(u);
			l>>=1;r>>=1;
		}
		push(tl);push(tr-1);
	}
	void raddv(int l,int r,ll u){
		l+=n;r+=n;
		pull(l);pull(r-1);
		int tl=l;int tr=r;
		while(l<r){
			if(l%2) arr[l++].addv(u);
			if(r%2) arr[--r].addv(u);
			l>>=1;r>>=1;
		}
		push(tl);push(tr-1);
	}
	ll query(int l,int r){
		l+=n;r+=n;
		ll sum=0;
		pull(l);pull(r-1);
		while(l<r){
			if(l%2) sum=MA(sum,arr[l++].mv2);
			if(r%2) sum=MA(sum,arr[--r].mv2);
			l>>=1;r>>=1;
		}
		return MM(sum,invtwo);
	}



} segtree;






int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	segtree.init();
	while(Q--){
		int type;cin>>type;
		if(type==1){
			int l,r;ll x;cin>>l>>r>>x;
			l--;
			segtree.raddm(l,r,x);
		}
		if(type==2){
			int l,r;ll x;cin>>l>>r>>x;
			l--;
			segtree.raddv(l,r,x);
		}
		if(type==3){
			int l,r;cin>>l>>r;
			l--;
			cout<<segtree.query(l,r)<<"\n";
		}
	}

	return 0;
}
