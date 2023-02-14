#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,m,q;
struct event{
	int l;
	int r;
	int v;
};

struct node{
	ll maxn=0;
	ll tag=0;
	void add(int l){
		tag+=l;
		maxn+=l;
	}
};
vector<node> seg;

void push(int l,int r,int ind){
	if(r-l<=1){
		return ;
	}
	if(seg[ind].tag){
		seg[2*ind].add(seg[ind].tag);
		seg[2*ind+1].add(seg[ind].tag);
	}
	seg[ind].tag=0;
}

void segadd(int l,int r,int L,int R,int ind,int v){
	push(L,R,ind);
	if(l==L && r==R){
		seg[ind].add(v);
		return ;
	}
	int M =(L+R)/2;
	if(r<=M) segadd(l,r,L,M,2*ind,v);
	else if(l>=M) segadd(l,r,M,R,2*ind+1,v);
	else{
		segadd(l,M,L,M,2*ind,v);
		segadd(M,r,M,R,2*ind+1,v);
	}
	seg[ind].maxn = max(seg[2*ind].maxn,seg[2*ind+1].maxn);
}

ll segquery(int l,int r,int L,int R,int ind){
	push(L,R,ind);
	if(l==L && r==R){
		return seg[ind].maxn;
	}
	int M = (L+R)/2;
	if(r<=M) return segquery(l,r,L,M,2*ind);
	else if(l>=M) return segquery(l,r,M,R,2*ind+1);
	return max(segquery(l,M,L,M,2*ind),segquery(M,r,M,R,2*ind+1));
}


vector<event> e;
struct cam{
	int l;
	int r;
	int k;
};

void add(int l,int r,int v){
	r++;
	segadd(l,r,1,n+1,1,v);
}

ll query(int l,int r){
	r++;
	return segquery(l,r,1,n+1,1);
}
vector<int> ans;
vector<cam> camera;
vector<int> stuff;
void do_things(int l,int r){
	for(int i=l;i<=r;i++){
		add(e[i].l,e[i].r,e[i].v);
	}
}
void undo_things(int l,int r){
	for(int i=r;i>=l;i--){
		add(e[i].l,e[i].r,-e[i].v);
	}
}

void split(vector<int> &arr,vector<int>& left,vector<int> &right){
	for(auto i : arr){
		ll val = query(camera[i].l,camera[i].r);
		if(val>=camera[i].k) left.push_back(i);
		else right.push_back(i);
	}
	vector<int>().swap(arr);
}

void total_bs(int l,int r,vector<int> &arr){
	if(l==r){
		for(auto i : arr) ans[i] = l;
		return ;
	}
	int mid = (l+r)/2;
	do_things(l,mid);
	vector<int> left,right;
	split(arr,left,right);
	total_bs(mid+1,r,right);
	undo_things(l,mid);
	total_bs(l,mid,left);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	seg.resize(4*n);
	e.resize(q);
	camera.resize(m);
	stuff.resize(m);	
	ans.resize(m);
	for(int i=0;i<m;i++) stuff[i]=i;
	for(int i=0;i<m;i++){
		cin>>camera[i].l>>camera[i].r>>camera[i].k;
		
	}
	for(int i=0;i<q;i++){
		cin>>e[i].l>>e[i].r>>e[i].v;
	}
	total_bs(0,q, stuff);
	for(int i=0;i<m;i++){
		ans[i]++;	
		if(ans[i]>q){
			cout<<-1<<" ";
		}else{
			cout<<ans[i]<<" ";
		}
	}
	cout<<"\n";
	return 0;
}
