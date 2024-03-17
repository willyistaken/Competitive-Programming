#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
vector<int> v;
struct SEG{
	struct node{
		int num;
		int maxn;
		int smaxn=-1;
		int maxncnt=1;
		int tag=0;
		void put(int c){
			if(c>=maxn){
				return;
			}
			if(c<maxn && c>smaxn){
				if(maxncnt&1){num^=maxn;num^=c;}
				maxn = c;
				tag=c;
				return;
			}
			assert(1==0);
		}
	};
	int n;
	vector<node> arr;	
	void init(int _n){
		n = _n;	
		arr.resize(4*n);
	}
	node merge(const node &a,const node &b)	{
		node r;	
		r.num = a.num^b.num;
		if(a.maxn==b.maxn){
			r.maxn = a.maxn;
			r.maxncnt=a.maxncnt+b.maxncnt;		
			r.smaxn = max(a.smaxn,b.smaxn);
		}else if(a.maxn>b.maxn){
			r.maxn = a.maxn;
			r.maxncnt=a.maxncnt;	
			r.smaxn = max(b.maxn,a.smaxn);
		}else{
			r.maxn = b.maxn;
			r.maxncnt=b.maxncnt;
			r.smaxn = max(a.maxn,b.smaxn);
		}
		return r;
	}
	void push(int ind){
		if(arr[ind].tag){
			arr[2*ind].put(arr[ind].tag);
			arr[2*ind+1].put(arr[ind].tag);
			arr[ind].tag=0;
		}
	}
	void modify(int l,int r,int c,int L,int R,int ind){
		if((arr[ind].maxn<=c)) return;
		if((L==l && R==r) && arr[ind].smaxn<c){
			arr[ind].put(c);
			return;
		}
		push(ind);
		int M = (L+R)/2;
		if(r<=M) modify(l,r,c,L,M,2*ind)	;
		else if(l>M) modify(l,r,c,M+1,R,2*ind+1);
		else{
			modify(l,M,c,L,M,2*ind);
			modify(M+1,r,c,M+1,R,2*ind+1);
		}
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
	int query(int l,int r,int L,int R,int ind){
		if(L==l && R==r) return arr[ind].num;
		push(ind);
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		else if(l>M) return query(l,r,M+1,R,2*ind+1);
		return query(l,M,L,M,2*ind)^query(M+1,r,M+1,R,2*ind+1);
	}
	void build(int l,int r,int ind){
		if(l==r){
			arr[ind].num=v[l];
			arr[ind].maxn=v[l];
			return;
		}
		int m = (l+r)/2;
		build(l,m,2*ind);
		build(m+1,r,2*ind+1);
		arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;	
	SEG seg;	
	seg.init(n);
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	seg.build(0,n-1,1);
	while(q--){
		int t;cin>>t;
		if(t){
			int l,r;cin>>l>>r;
			l--;r--;
			cout<<seg.query(l,r,0,n-1,1)<<"\n";
		}else{
			int l,r,c;cin>>l>>r>>c;	
			l--;r--;
			seg.modify(l,r,c,0,n-1,1);
		}
	}
	return 0;
}
