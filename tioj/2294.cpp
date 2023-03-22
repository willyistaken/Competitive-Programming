#pragma GCC optimize("O3")
#pragma GCC target("lzcnt")
#include "lib2294.h"
#include<bits/stdc++.h>
using namespace std;
//#include<bits/extc++.h>
//__gnu_pbds



int n;
struct node{
	int ans=0;
	int sum = 0;
	int add=0;
	int replace=0;
	int len = 1;
	void plus(int v){
		sum+=v*len;
		ans+=v;
		add+=v;
	}
	void setv(int v){
		sum = v*len;
		add=0;
		ans=v;
		replace=v;
	}
};



vector<node> segtree;

void pull(int ind){
	if(ind==1) return;
	pull(ind>>1);
	if(segtree[ind>>1].replace){
		segtree[ind].setv(segtree[ind>>1].replace);
		segtree[ind^1].setv(segtree[ind>>1].replace);
		segtree[ind>>1].replace=0;
	}
	segtree[ind].plus(segtree[ind>>1].add);
	segtree[ind^1].plus(segtree[ind>>1].add);
	segtree[ind>>1].add=0;
}
/*
void pull(int i){
	for(int h=sizeof(int) * __CHAR_BIT__  - 1 - __builtin_clz(i);h>=0;h--){
		int ind = i>>h;
		if(segtree[ind>>1].replace){
		segtree[ind].setv(segtree[ind>>1].replace);
		segtree[ind^1].setv(segtree[ind>>1].replace);
		segtree[ind>>1].replace=0;
		}
		segtree[ind].plus(segtree[ind>>1].add);
		segtree[ind^1].plus(segtree[ind>>1].add);
		segtree[ind>>1].add=0;
	}
}*/
void push(int ind){
	ind>>=1;
	while(ind){
		segtree[ind].ans =(segtree[ind].replace) ? segtree[ind].replace+segtree[ind].add:max(segtree[ind<<1].ans,segtree[(ind<<1)^1].ans)+segtree[ind].add;
		segtree[ind].sum =(segtree[ind].replace) ? (segtree[ind].replace+segtree[ind].add)*segtree[ind].len:(segtree[ind<<1].sum+segtree[(ind<<1)^1].sum)+segtree[ind].add*segtree[ind].len;
		ind>>=1;
	}
}

int query_sum(int l,int r){
	l+=n; r+=n;
	int result=0;
	pull(l);pull(r-1);
	int tl=l;int tr=r;
	while(l<r){
		if(l & 1){
			result+=segtree[l++].sum;
		}
		if(r & 1){
			result+=segtree[--r].sum;
		}
		l>>=1;r>>=1;
	}
	push(tl);push(tr-1);
	return result;
}

void addr(int l,int r,int v){
	l+=n; r+=n;
	pull(l);pull(r-1);
	int tl=l;int tr=r;
	while(l<r){
		if(l & 1){
			segtree[l++].plus(v);
		}
		if(r & 1){
			segtree[--r].plus(v);
		}
		l>>=1;r>>=1;
	}
	push(tl);push(tr-1);
}

void replacer(int l,int r,int v){
	l+=n; r+=n;
	pull(l);pull(r-1);
	int tl=l;int tr=r;
	while(l<r){
		if(l & 1){
			segtree[l++].setv(v);
		}
		if(r & 1){
			segtree[--r].setv(v);
		}
		l>>=1;r>>=1;
	}
	push(tl);push(tr-1);
}

int query_max(int l,int r){
	l+=n; r+=n;
	pull(l);pull(r-1);
	int tl=l;int tr=r;
	int result=INT_MIN;
	while(l<r){
		if(l & 1){
			result = max(segtree[l++].ans,result);
		}
		if(r & 1){
			result = max(segtree[--r].ans,result);
		}
		l>>=1;r>>=1;
	}
	push(tl);push(tr-1);
	return result;
}
void built(int i){
	if(i>=n) return;
	built(i<<1);
	built((i<<1)^1);
	segtree[i].len = segtree[i<<1].len+segtree[(i<<1)^1].len;
}


void  init_array(int N){
	 n=  N;
	segtree.resize(2*N);
	built(1);
}


void add_range(int L,int R,int x){
	addr(L,R,x);
}

void set_range(int L,int R,int x){
 	replacer(L,R,x);
}

int sum_range(int L,int R){
	int ans = query_sum(L,R);
	if(ans<0){ans+=INT_MAX;ans+=1;}
	return ans;
}

int max_range(int L,int R){
	return query_max(L,R);
}

