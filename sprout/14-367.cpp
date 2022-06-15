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
		segtree[ind].ans = max(segtree[2*ind].ans,segtree[2*ind+1].ans);
		ind>>=1;
	}
}

void change(int l,int r,int v,vector<node> &segtree){
	l+=n;r+=n;
	while(l<r){
		if(l%2){
			pull(l,segtree);
			segtree[l].update(v);
			push(l,segtree);
			l++;
		}
		if(r%2){
			--r;
			pull(r,segtree);
			segtree[r].update(v);
			push(r,segtree);
		}
		l>>=1;r>>=1;
	}
}

int query(int l,int r,vector<node> &segtree){
	l+=n;r+=n;
	int result= INT_MIN;
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
		l>>=1;
		r>>=1;
	}
	return result;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	vector<node> segtree(2*n);
	int q;cin>>q;
	for(int i=0;i<n;i++) {
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
