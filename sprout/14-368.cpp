#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node{
	int ans=0;
	int add=0;
	int replace=0;
	void plus(int v){
		ans+=v;
		add+=v;
	}
	void setv(int v){
		add=0;
		ans=v;
		replace=v;
	}
	void print(){
		cout<<" "<<ans<<" "<<add<<" "<<replace<<"\n";
	}
};
void pull(int ind,vector<node> &segtree){
	if(ind==1) return;
	pull(ind>>1,segtree);
	if(segtree[ind>>1].replace){
		segtree[ind].setv(segtree[ind>>1].replace);
		segtree[ind^1].setv(segtree[ind>>1].replace);
		segtree[ind>>1].replace=0;
	}
	segtree[ind].plus(segtree[ind>>1].add);
	segtree[ind^1].plus(segtree[ind>>1].add);
	segtree[ind>>1].add=0;
}
void push(int ind,vector<node> &segtree){
	ind>>=1;
	while(ind){
		segtree[ind].ans = max(segtree[2*ind].ans,segtree[2*ind +1].ans);
		ind>>=1;
	}
}

void addr(int l,int r,int v,vector<node> &segtree){
	l+=n; r+=n;
	while(l<r){
		if(l%2){
			pull(l,segtree);
			segtree[l].plus(v);
			push(l,segtree);
			l++;
		}
		if(r%2){
			--r;
			pull(r,segtree);
			segtree[r].plus(v);
			push(r,segtree);
		}
		l>>=1;r>>=1;
	}
}

void replacer(int l,int r,int v,vector<node> &segtree){
	l+=n; r+=n;
	while(l<r){
		if(l%2){
			pull(l,segtree);
			segtree[l].setv(v);
			push(l,segtree);
			l++;
		}
		if(r%2){
			--r;
			pull(r,segtree);
			segtree[r].setv(v);
			push(r,segtree);
		}
		l>>=1;r>>=1;
	}
}

int query(int l,int r,vector<node> &segtree){
	l+=n; r+=n;
	int result=INT_MIN;
	while(l<r){
		if(l%2){
			pull(l,segtree);
			result = max(segtree[l].ans,result);
			l++;
		}
		if(r%2){
			--r;
			pull(r,segtree);
			result = max(segtree[r].ans,result);
		}
		l>>=1;r>>=1;
	}
	return result;
}
void built(int i,vector<node> &segtree){
	if(i>=n) return;
	built(i*2,segtree);
	built(2*i+1,segtree);
	segtree[i].ans = max(segtree[2*i].ans,segtree[2*i+1].ans);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;	int q;	cin>>q;
	vector<node> segtree(2*n);
	for(int i=0;i<n;i++) cin>>segtree[i+n].ans;
	built(1,segtree);
	for(;q;q--){
		int type;cin>>type;
		int l,r;cin>>l>>r;
		l-=1;
		if(type==1){
			int v;cin>>v;
			addr(l,r,v,segtree);	
		}
		if(type==2){
			cout<<query(l,r,segtree)<<endl;
		}
		if(type==3){
			int v;cin>>v;
			replacer(l,r,v,segtree);
		}
	}
	return 0;
}

