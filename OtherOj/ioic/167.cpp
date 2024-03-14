#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int C;
bool nand(bool x,bool y){
	return !(x & y);
}

struct node{
	bool f[30][2];
	node(){
		for(int i=0;i<C;i++){
			f[i][1]=1;
			f[i][0]=0;
		}
	}
};

struct SEG{
	int n;
	node merge(const node &a,const node &b){
		node r;
		for(int i=0;i<C;i++){
			r.f[i][0] = b.f[i][a.f[i][0]];
			r.f[i][1] = b.f[i][a.f[i][1]];
		} 
		return r;
	};
	vector<node> arr;
	void init(int _n){
		n = _n;	
		arr.resize(4*n);
	}
	void modify(int x,int v,int L,int R,int ind){
		if(L==R){
			node g;
			for(int i=0;i<C;i++){
				bool b = (v>>i)&1;
				g.f[i][0] = 1; 
				g.f[i][1] = !b;
			}
			arr[ind]=g;
			return;
		}
		int M  = (L+R)/2;
		if(x<=M) modify(x,v,L,M,2*ind);
		else if(x>M) modify(x,v,M+1,R,2*ind+1);
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	node query(int l,int r,int L,int R,int ind){
		if(l==L && r==R) return arr[ind];
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		if(l>M) return query(l,r,M+1,R,2*ind+1);
		return merge(query(l,M,L,M,2*ind),query(M+1,r,M+1,R,2*ind+1));
	}
} seg;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q>>C;
	seg.init(n)	;
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		seg.modify(i,a,1,n,1);
		arr[i]=a;
	}
	for(int ff=0;ff<q;ff++){
		int t;cin>>t;
		if(t==1){
			int l,r;cin>>l>>r;
			if(l==r){
				cout<<arr[l]<<"\n";
			}else{
				node k  = seg.query(l+1,r,1,n,1);
				int g = 0;
				for(int i=0;i<C;i++){
					g+=(1<<i)*k.f[i][(arr[l]>>i)&1];
				}
				cout<<g<<"\n";
			}
		}else{
			int x,v;cin>>x>>v;
			seg.modify(x,v,1,n,1);
			arr[x]=v;
		}
	}

	return 0;
}
