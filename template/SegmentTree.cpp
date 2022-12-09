#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct SEG {
    vector<int> arr;
    int n;
    void init(int s) {
        n = s;
        arr.resize(4*n,1e9);
    }
    int combine(int a,int b) {
        return min(a,b);
    }
    int query(int l,int r,int ql,int qr,int ind) {
        if(l>=ql && r<=qr) return arr[ind];
        if(l>=qr || r<ql) return 1e9;
        int mid = (l+r)/2;
        return min(query(l,mid,ql,qr,2*ind),query(mid,r,ql,qr,2*ind+1));
    }
	void modify(int qi,int l,int r,int ind,int v){
		if(r-l==1 && qi==l) {
			arr[ind] = v;
		}else if(qi>=l && qi<r){ 
			int mid = (r+l)/2;
			modify(qi,l,mid,2*ind,v);
			modify(qi,mid,r,2*ind+1,v);
		}else return ;
	}
};
