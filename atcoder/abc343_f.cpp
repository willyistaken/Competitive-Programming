#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct seg{
	int n;
	struct node{
		int maxn[2]={0,-1};
		int cnt[2] = {1,0};
		void print(){
			cout<<maxn[0]<<":"<<cnt[0]<<"|";	
			cout<<maxn[1]<<":"<<cnt[1]<<"\n";	
		}
	};
	vector<node> arr;
	void init(int _n){
		n = _n;
		arr.resize(4*n);
		for(int i=0;i<4*n;i++){
			arr[i].maxn[0]=0;
			arr[i].maxn[1]=-1;
			arr[i].cnt[0]=1;
			arr[i].cnt[1]=0;
		}
	};
	
	node merge(node a,node b){
		node r;
		if(a.maxn[0]<b.maxn[0]) swap(a,b);
		if(a.maxn[0]>b.maxn[0]){
			r.maxn[0] = a.maxn[0];
			r.cnt[0]=a.cnt[0];
			if(b.maxn[0]>a.maxn[1]){
				r.maxn[1] = b.maxn[0];
				r.cnt[1] = b.cnt[0];
			}else if(b.maxn[0]==a.maxn[1]){
				r.maxn[1] = b.maxn[0];
				r.cnt[1] = a.cnt[1]+b.cnt[0];
			}else{
				r.maxn[1] = a.maxn[1];
				r.cnt[1] = a.cnt[1];
			}

		}else{
			r.maxn[0] = a.maxn[0];
			r.cnt[0] = a.cnt[0]+b.cnt[0];
			if(a.maxn[1]<b.maxn[1]) swap(a,b);
			if(a.maxn[1]>b.maxn[1]){
				r.maxn[1] = a.maxn[1];
				r.cnt[1] = a.cnt[1];
			}else{
				r.maxn[1] = a.maxn[1];
				r.cnt[1] = a.cnt[1]+b.cnt[1];
			}
		}
		return r;
	}
	void modify(int x,int v,int L,int R,int ind){
		if(L==R){
			arr[ind].maxn[0]=v;
			return ;
		}
		int M = (L+R)/2;
		if(x<=M) modify(x,v,L,M,2*ind);
		else modify(x,v,M+1,R,2*ind+1);
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	node query(int l,int r,int L,int R,int ind){
		if(L==l && r==R){
			return arr[ind];
		}
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		if(l>M) return query(l,r,M+1,R,2*ind+1);
		return merge(query(l,M,L,M,2*ind),query(M+1,r,M+1,R,2*ind+1));
	}
	void built(int l,int r,int ind){
		if(l==r) return;
		int m = (l+r)/2;
		built(l,m,2*ind);
		built(m+1,r,2*ind+1);
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	void print(int l,int r,int ind){
		cout<<ind<<"::";
		arr[ind].print();
		if(l==r) return;
		int m = (l+r)/2;
		print(l,m,2*ind);
		print(m+1,r,2*ind+1);
	}
} S;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	S.init(n);
	S.built(1,n,1);
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		S.modify(i,a,1,n,1);
	}
	while(q--){
		int t;cin>>t;
		if(t==1){
			int p,x;	 
			cin>>p>>x;
			S.modify(p,x,1,n,1);
		}else{
			int l,r;cin>>l>>r;	
			cout<<S.query(l,r,1,n,1).cnt[1]<<"\n";
		}
	}

	return 0;
}
