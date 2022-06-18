#include<bits/stdc++.h>
#include "lib1895.h"
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

void buildWall(int _n, int k, int op[], int l[], int r[], int h[], int finalHeight[]) {
    n = _n;
    vector<node> segtree(2*_n);
  
    for (int i = 0; i < k; ++i) {
        upd(l[i],r[i]+1,!(op[i]-1),h[i],segtree);
    }
    for (int i = 0; i < _n; ++i) {
        pull(i+_n,segtree);
        finalHeight[i] = segtree[i+_n].mx;
    }
}

