#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node{
	int ans=0;
	int tag=0;
	void update(int n){
		ans+=n;
		tag+=n;
	}
};

void pull(int ind,vector<node> &segtree){
	if(ind==1) return;
	pull(ind>>1,segtree);
	segtree[ind].update(segtree[ind>>1].tag);
	segtree[ind^1].update(segtree[ind>>1].tag);
	segtree[ind>>1].tag=0;

}
void push(int ind,vector<node> &segtree){
	ind>>=1;
	while(ind){
		segtree[ind].ans = max(segtree[2*ind].ans,segtree[2*ind+1].ans)+segtree[ind].tag;
		ind>>=1;
	}
}

void change(int l,int r,int v,vector<node> &segtree){
	l+=n;r+=n;
	pull(l,segtree);pull(r-1,segtree);
	int tl = l;int tr = r;
	while(l<r){
		if(l%2){
			
			segtree[l].update(v);
			l++;
		}
		if(r%2){
			--r;
			
			segtree[r].update(v);
		}
		l>>=1;r>>=1;
	}
	push(tl,segtree);push(tr-1,segtree);
}

int query(int l,int r,vector<node> &segtree){
	l+=n;r+=n;
	int result= INT_MIN;
	pull(l,segtree);pull(r-1,segtree);
	while(l<r){
		if(l%2){
			result = max(segtree[l].ans,result);
			l++;
		}
		if(r%2){
			--r;
			result = max(segtree[r].ans,result);
		}
		l>>=1;
		r>>=1;
	}
	return result;
}
inline int np2(int _n){
	_n--;
	_n |= _n>>1;
	_n |= _n>>2;
	_n |= _n>>4;
	_n |= _n>>8;
	_n |= _n>>16;
	_n++;
	return _n;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	int b = n;
	n = np2(n);
	vector<node> segtree(2*n);
	int q;cin>>q;
	for(int i=0;i<b;i++) {
		int a;cin>>a;
		segtree[i+n].ans=a;
		push(i+n,segtree);
	}
	for(;q;q--){
		int type;cin>>type;
		int l,r;cin>>l>>r;
		l-=1;
		if(type==1){
			int v;cin>>v;
			change(l,r,v,segtree);
		}else{
			cout<<query(l,r,segtree)<<endl;
		}
	}

	return 0;
}
