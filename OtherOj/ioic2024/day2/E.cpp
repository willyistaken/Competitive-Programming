#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll


struct SEG{
	struct node{
		int plate[2] = {-1,-1};
		int sum = 0;
		void add(int b,int s,int t){
			if(plate[0]==-1){
				plate[0]=b;
				sum+=s;
			}else{
				sum+=(plate[1]^b)+s;
			}
			plate[1]=t;
		}
	};
	vector<node> arr;	
	int n;
	void init(int _n){
		arr.resize(4*_n);
		n = _n;
	}
	void push(int ind){
		if(arr[ind].plate[0]!=-1){
			if(2*ind<4*n){
				arr[2*ind].add(arr[ind].plate[0],arr[ind].sum,arr[ind].plate[1]);
			}
			if(2*ind+1<4*n){
				arr[2*ind+1].add(arr[ind].plate[0],arr[ind].sum,arr[ind].plate[1]);
			}
			arr[ind].plate[0]=-1;
			arr[ind].plate[1]=-1;
			arr[ind].sum=0;
		}
	}
	void radd(int l,int r,int L,int R,int ind,int p){
		if(l==L && r==R){ 
			arr[ind].add(p,0,p);
			return;
		}
		push(ind);
		int M = (L+R)/2;
		if(r<=M) radd(l,r,L,M,2*ind,p);
		else if(l>M) radd(l,r,M+1,R,2*ind+1,p);
		else{
			radd(l,M,L,M,2*ind,p);
			radd(M+1,r,M+1,R,2*ind+1,p);
		}
	}
	int query(int L,int R,int ind,int x){
		if(R==L){
			return arr[ind].sum;
		} 
		push(ind);
		int M = (L+R)/2;
		if(x<=M) return query(L,M,2*ind,x);
		else return query(M+1,R,2*ind+1,x);
	}
	void print(int l,int r,int ind){
		cout<<ind<<":::"<<l<<" "<<r<<":"<<arr[ind].plate[0]<<","<<arr[ind].plate[1]<<","<<arr[ind].sum<<"\n";
		if(l==r) return ;
		int m = (l+r)/2;
		print(l,m,2*ind);
		print(m+1,r,2*ind+1);
	}
	
} seg;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;	
	seg.init(n);
	while(q--){
		int t;cin>>t;
		if(t==1){
			int l,r,p;cin>>l>>r>>p;
			seg.radd(l,r,1,n,1,p);
		}else{
			int x;cin>>x; 
			cout<<seg.query(1,n,1,x)<<"\n";
		}
	}
	return 0;
}
