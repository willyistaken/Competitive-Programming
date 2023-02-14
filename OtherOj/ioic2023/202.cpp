#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct line{
	ll m=0;ll x=0;
	ll val(ll k){
		return  m*k+x;
	}
};
struct seg{
	line a;	
	seg* lc=nullptr;
	seg* rc=nullptr;
	seg(line b={0,0}){
		a = b;
	}
};

void insert(int l,int r,seg* &cur,line b){
	if(cur==nullptr){
		cur = new seg(b);
		return ;
	}
	if(r-l==1){
		if(cur->a.val(l)<b.val(l)){
			cur->a = b;
		}
		return ;
	}
	int m = l+((r-l)/2);
	if(cur->a.m>b.m) swap(cur->a,b);
	if(b.val(m)>cur->a.val(m)){
		swap(cur->a,b);
		insert(l,m,cur->lc,b);
	}else{
		insert(m,r,cur->rc,b);
	}
}

ll query(int l,int r,seg* cur,ll x){
	if(cur==nullptr){
		return 0;
	}
	int m = l+(r-l)/2;
	if(x<m) return max(query(l,m,cur->lc,x),cur->a.val(x));
	return max(query(m,r,cur->rc,x),cur->a.val(x));
}
const int N = 1e9+5;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	seg* a = nullptr;
	bool flag=0;
	for(int i=0;i<q;i++){
		int type;cin>>type;
		if(type==2) {
			assert(1==0);
		}
		if(type==0){
			int x;cin>>x;
			ll k = query(0,N,a,x);
			if(!flag) cout<<"double is good at problem setting\n";
			else cout<<k<<"\n";
		}else{
			flag=1;
			int m,x;cin>>m>>x;
			line p = {m,x};
			insert(0,N,a,p);
		}
	}
	return 0;
}
