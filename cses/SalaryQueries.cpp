#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct SEG{
	struct node{
		int v = 0;
		node* lc = nullptr;
		node* rc = nullptr;
	};
	node* head = new node;
	int get(node* cur){
		if(cur==nullptr) return 0;
		else return cur->v;
	}
	node* modify(int ind,int v,int L,int R,node* cur){
		if(cur==nullptr){
			cur = new node;
		}
		if(L==ind && R-L==1) {
			cur->v+=v;
			return cur;
		}
		int M = L+((R-L)/2);
		if(ind<M && ind>=L) cur->lc = modify(ind,v,L,M,cur->lc);
		if(ind>=M && ind<R) cur->rc = modify(ind,v,M,R,cur->rc);
		cur->v = get(cur->lc)+get(cur->rc); // important
		return cur;
	}

	int query(int l,int r,int L,int R,node* cur){
		if(cur==nullptr) return 0;
		if(l==L && r==R) return get(cur);
		int M = L +((R-L)/2);
		if(r<=M) return query(l,r,L,M,cur->lc);
		if(l>=M) return query(l,r,M,R,cur->rc);
		return query(l,M,L,M,cur->lc)+query(M,r,M,R,cur->rc);	
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	SEG seg;	
	int n,q;cin>>n>>q;
	int L = 0;int R = 1e9+5;
	int sal[n];
	for(int i=0;i<n;i++){
		int a;cin>>a;
		sal[i]=a;
		seg.head = seg.modify(a,1,L,R,seg.head);
	}
	while(q--){
		char t;cin>>t;
		if(t=='?'){
			int a,b;cin>>a>>b;
			cout<<seg.query(a,b+1,L,R,seg.head)<<"\n";
		}else{
			int k,a;cin>>k>>a;
			k--;
			seg.head = seg.modify(sal[k],-1,L,R,seg.head);
			sal[k]=a;
			seg.head = seg.modify(sal[k],1,L,R,seg.head);
		}
	}
	return 0;
}

