#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int M;
struct FC{
	int a,b,d,t;		
	ll v,u;
	FC(int f=0){
		if(f>0){
			d = 0;
			t = M-f;
			a = f;
			b = M;
			v = f;
			u = 0;
		}else{
			d = -f;	
			t = M;
			a = 0;
			b = M+f;
			v = 0;
			u = 0;
		}
	}
	int getF(int x){
		return min(max(d+(x-a),d),t);
	}
	ll getC(int x){
		return max((v-x),u);
	}
};

FC operator+(FC &x,FC &y){
	FC r = FC(0);	
	r.d = y.getF(x.d);
	r.t = y.getF(x.t); 
	if(r.d==r.t){
		r.a = M;
		r.b = M;
	}else{
		r.a = max(x.a,x.a+y.a-x.d);
		r.b = max(x.b,x.b+y.b-x.t);
	}
	r.v = x.getC(0)+y.getC(x.getF(0));
	r.u = x.getC(M)+y.getC(x.getF(M));
	return r;
}

struct segtree{
	vector<FC> arr;
	int n;
	segtree(int _s){
		n = _s;	
		arr.resize(2*n);
	}
	void built(int ind){
		if(2*ind>=2*n) return;
		if(2*ind+1>=2*n) arr[ind] = arr[2*ind];
		built(2*ind);
		built(2*ind+1);
		arr[ind] = arr[2*ind]+arr[2*ind+1];
	}
	void modify(int ind,int v){
		ind+=n;
		arr[ind] = FC(v);
		while(ind){
			if(ind&1) arr[ind>>1] = arr[ind^1]+arr[ind];
			else arr[ind>>1] = arr[ind]+arr[ind^1];
			ind>>=1;
		}
	}
	FC query(int l,int r){
		l+=n;
		r+=n;
		FC  lre = FC(0);
		FC  rre = FC(0);
		while(l<r){
			if(l&1)	lre = lre+arr[l++];
			if(r&1) rre = arr[--r]+rre;
			l>>=1;
			r>>=1;
		}
		lre = lre+rre;
		return (lre);
	}
};


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q>>M; 
	segtree sg = segtree(n);
	for(int k=0+n;k<=n-1+n;k++){
		int a;cin>>a;
		sg.arr[k] = FC(a);
	}
	sg.built(1);
	while(q--){
		int t;cin>>t;
		if(t==1){
			int p,x;cin>>p>>x;
			p--;
			sg.modify(p,x);
		}else{
			int l,r,y;cin>>l>>r>>y;	
			l--;
			FC result = sg.query(l,r); 
			cout<<result.getC(y)<<" "<<result.getF(y)<<"\n";
			//result.print();
		}
	}
	return 0;
}
