#include<bits/stdc++.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
using namespace std;
typedef long long ll;

struct node{
	int mx=0;
	int mn=1e7;
	void update(bool type,int h){
		mx = (type) ? MAX(mx,h):MIN(mx,h);
		mn = (type) ? MAX(mn,h):MIN(mn,h);
	}
};
int n;

void pull(int ind,vector<node> &segtree){
	if(ind==1) return;
	pull(ind>>1,segtree);
	if(segtree[ind>>1].mx!=0 || segtree[ind>>1].mn != 1e7){
	segtree[ind].update(1,segtree[ind>>1].mx);
	segtree[ind^1].update(1,segtree[ind>>1].mx);
	segtree[ind].update(0,segtree[ind>>1].mn);
	segtree[ind^1].update(0,segtree[ind>>1].mn);
	segtree[ind>>1].mx=0;
	segtree[ind>>1].mn=1e7;
	}
}

void upd(int l,int r,bool type,int h,vector<node> &segtree){
	l+=n;r+=n;
	while(l<r){
		if(l & 1){
			pull(l,segtree);
			segtree[l].update(type,h);
			++l;
		}
		if(r & 1){
			--r;
			pull(r,segtree);
			segtree[r].update(type,h);
		}
		l>>=1;
		r>>=1;
	}
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	vector<node> segtree(2*n);
	int m;cin>>m;
	int type;int l,r;int h;
	for(int i=0;i<m;i++){
		cin>>type;
		cin>>l>>r;
		cin>>h;
		upd(l,r+1,!(type-1),h,segtree);	
	}
	for(int i=0;i<n;i++){
		pull(i+n,segtree);
		cout<<MIN(segtree[i+n].mx,segtree[i+n].mn)<<"\n";
	}
	return 0;
}
