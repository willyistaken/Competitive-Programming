#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node{
	int ans=0;
	int add=0;
	int replace=0;
	void plus(int n){
		ans+=n;
		add=+n;
	}
	void setv(int n){
		add=0;
		ans=n;
		replace=n;
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
void built(vector<node> &segtree){
	int t[n];
	for(int i=0;i<n;i++) cin>>t[i];
	for(int i=2*n-1;i>=1;i--){
		if(i>=n) segtree[i].ans = t[i-n];
		if(i%2==0) segtree[i>>1].ans = max(segtree[i].ans,segtree[i^1].ans);
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;		
	vector<node> segtree(2*n);
	int q;cin>>q;
	built(segtree);
	for(;q;q--){
		int type;cin>>type;
		int l,r;cin>>l>>r;
		l-=1;
		if(type==1){
			int v;cin>>v;addr(l,r,v,segtree);	
		}
		if(type==2){
			cout<<query(l,r,segtree)<<endl;
		}
		if(type==3){
			int v;cin>>v;replacer(l,r,v,segtree);
		}

	}
	return 0;
}

