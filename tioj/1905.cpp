#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
struct node{
	ll mx[2];
	ll mn[2];
	void init(){
		mx[0]=-1;mx[1]=-1;
		mn[0]=LONG_LONG_MAX;mn[1]=LONG_LONG_MAX;
	}
	void print(){
		cout<<"MAX:"<<mx[0]<<" "<<mx[1]<<"\n";
		cout<<"MIN:"<<mn[0]<<" "<<mn[1]<<"\n";
	}
};

node combine(const node a,const node b){
		node r;
		r.init();
		int ahead=0;
		int bhead=0;
		for(int i=0;i<2;i++){
			if(a.mx[ahead]>=b.mx[bhead]) r.mx[i] = a.mx[ahead++];	
			else	r.mx[i] = b.mx[bhead++];	
		}
		ahead=0;
		bhead=0;
		for(int i=0;i<2;i++){
			if(a.mn[ahead]<=b.mn[bhead]) r.mn[i] = a.mn[ahead++];	
			else	r.mn[i] = b.mn[bhead++];	
		}
		return r;
}
vector<node> segtree;

void init(){
	segtree.resize(2*n);
	for(int i=0;i<k;i++){
		ll a;cin>>a;
		segtree[i+n].mx[0]=a;
		segtree[i+n].mx[1]=-1;
		segtree[i+n].mn[0]=a;
		segtree[i+n].mn[1]=LONG_LONG_MAX;
	}
	for(int i=n-1;i>=1;i--){
		segtree[i] = combine(segtree[2*i],segtree[2*i+1]);
	}
}

ll query(int l,int r){
	node result;
	result.init();
	l+=n;r+=n;
	while(l<r){
		if(l%2) result = combine(result,segtree[l++]);
		if(r%2) result = combine(result,segtree[--r]);
		l>>=1;r>>=1;
	}
	return min(result.mx[0]-result.mx[1],result.mn[1]-result.mn[0]);
}
int np2(int _n);
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	k = n;
	n = np2(n);
	init();
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		l--;
		cout<<query(l,r)<<"\n";
	}
	return 0;
}

int np2(int _n){
	_n--;
	_n |= _n>>1;
	_n |= _n>>2;
	_n |= _n>>4;
	_n |= _n>>8;
	_n |= _n>>16;
	return _n++;
}
