#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int mx=0;
	int mn=100000000;
	void update(bool type,int h){
		if(type){
			mx = max(mx,h);
			mn = max(mn,h);
		}else{
			mx = min(mx,h);
			mn = min(mn,h);
		}
	}
};
int n;

void pull(int ind,vector<node> &segtree){
	if(ind<=1) return;
	pull(ind>>1,segtree);
	segtree[ind].mx = max(segtree[ind].mx,segtree[ind>>1].mx);
	segtree[ind].mx = min(segtree[ind].mx,segtree[ind>>1].mn);
	segtree[ind].mn = max(segtree[ind].mn,segtree[ind>>1].mx);
	segtree[ind].mn = min(segtree[ind].mn,segtree[ind>>1].mn);
	segtree[ind^1].mx = max(segtree[ind^1].mx,segtree[ind>>1].mx);
	segtree[ind^1].mx = min(segtree[ind^1].mx,segtree[ind>>1].mn);
	segtree[ind^1].mn = max(segtree[ind^1].mn,segtree[ind>>1].mx);
	segtree[ind^1].mn = min(segtree[ind^1].mn,segtree[ind>>1].mn);
	segtree[ind>>1].mx=0;
	segtree[ind>>1].mn=10000000;
}

void upd(int l,int r,bool type,int h,vector<node> &segtree){
	l+=n;r+=n;
	while(l<r){
		if(l%2){
			pull(l,segtree);
			segtree[l].update(type,h);
			l++;
		}
		if(r%2){
			--r;
			pull(r,segtree);
			segtree[r].update(type,h);
		}
		l>>=1;
		r>>=1;
	}
}
void pushleaf(int ind,vector<node> &segtree){
	if(ind>=n) return;
	ind<<=1;
	segtree[ind].mx = max(segtree[ind].mx,segtree[ind>>1].mx);
	segtree[ind].mx = min(segtree[ind].mx,segtree[ind>>1].mn);
	segtree[ind].mn = max(segtree[ind].mn,segtree[ind>>1].mx);
	segtree[ind].mn = min(segtree[ind].mn,segtree[ind>>1].mn);
	segtree[ind^1].mx = max(segtree[ind^1].mx,segtree[ind>>1].mx);
	segtree[ind^1].mx = min(segtree[ind^1].mx,segtree[ind>>1].mn);
	segtree[ind^1].mn = max(segtree[ind^1].mn,segtree[ind>>1].mx);
	segtree[ind^1].mn = min(segtree[ind^1].mn,segtree[ind>>1].mn);
	segtree[ind>>1].mx=0;
	segtree[ind>>1].mn=10000000;
	pushleaf(ind,segtree);
	pushleaf(ind^1,segtree);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	vector<node> segtree(2*n);
	int m;cin>>m;
	while(m--){
		int type;cin>>type;
		int l,r;cin>>l>>r;r+=1;
		int h;cin>>h;
		upd(l,r,!(type-1),h,segtree);	
	}
		pushleaf(1,segtree);
		for(int i=0;i<n;i++){
			cout<<min(segtree[i+n].mx,segtree[i+n].mn)<<endl;
		}
	return 0;
}
