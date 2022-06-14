#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

struct node{
	int zcount=1;
	int ocount=0;
	int tcount=0;
	int reset=0;
	int add=0;
	void Freset(){
			zcount = zcount+ocount+tcount;
			ocount=0;
			tcount=0;
			add=0;
			reset=1;
	}

	void plus(int n){
		add+=n;
		n = n%3;
		for(int i=0;i<n;i++){
			swap(zcount,ocount);
			swap(zcount,tcount);
		}
	}

};

void pull(int ind,vector<node> &segtree){
	if(ind==1) return;
	pull(ind>>1,segtree);
	if(segtree[ind>>1].reset){
		segtree[ind].Freset();
		segtree[ind^1].Freset();
	}
	segtree[ind>>1].reset=0;
	segtree[ind].plus(segtree[ind>>1].add);
	segtree[ind^1].plus(segtree[ind>>1].add);
	segtree[ind>>1].add=0;
}

void push(int ind,vector<node> &segtree){
		ind>>=1;
		while(ind){
			segtree[ind].zcount = segtree[ind*2].zcount + segtree[2*ind +1].zcount;
			segtree[ind].ocount = segtree[ind*2].ocount + segtree[2*ind +1].ocount;
			segtree[ind].tcount = segtree[ind*2].tcount + segtree[2*ind +1].tcount;
			ind>>=1;
		}
}

void change(int l,int r,vector<node> &segtree){
	l+=n;r+=n;
	while(l<r){
		if(l%2){
			pull(l,segtree);
			segtree[l].plus(1);	
			push(l,segtree);
			l++;
		}
		if(r%2){
			--r;
			pull(r,segtree);
			segtree[r].plus(1);
			push(r,segtree);
		}
		l>>=1;r>>=1;
	}
}

void setz(int l,int r,vector<node> &segtree){
	l+=n;r+=n;
	while(l<r){
		if(l%2){
			pull(l,segtree);
			segtree[l].Freset();
			push(l,segtree);
			l++;
		}
		if(r%2){
			--r;
			pull(r,segtree);
			segtree[r].Freset();
			push(r,segtree);
		}
		l>>=1;r>>=1;

	}
}

int query(int l,int r,vector<node> &segtree){
	l+=n;r+=n;
	int sum=0;
	while(l<r){
		if(l%2){
			pull(l,segtree);
			sum += segtree[l].zcount;
			push(l,segtree);
			l++;
		}
		if(r%2){
			--r;
			pull(r,segtree);
			sum += segtree[r].zcount;
			push(r,segtree);
		}
		l>>=1;r>>=1;
	}
	return sum;
}


int main(){
	cin>>n;
	int m;cin>>m;
	vector<node> segtree(2*n);
	for(int i=0;i<n;i++){
		push(i+n,segtree);
	}
	for(;m;m--){
	string s;cin>>s;
	int l,r;cin>>l>>r;
	l-=1;
	if(s[0]=='T'){
		change(l,r,segtree);
	}
	if(s[0]=='R'){
		setz(l,r,segtree);
	}
	if(s[0]=='C'){
		cout<<query(l,r,segtree)<<endl;
	}

	}
	return 0;
}
