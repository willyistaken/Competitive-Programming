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
        if(l>=qr || r<=ql) return 1e9;
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
			arr[ind] = min(arr[2*ind],arr[2*ind+1]);
		}else return ;
	}
};






int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	SEG seg;
	seg.init(n);
	for(int i=0;i<n;i++){
		int a;cin>>a;
		seg.modify(i,0,n,1,a);
	}
	while(q--){
		int type;cin>>type;
		int a,b;cin>>a>>b;
		a--;
		if(type==1){
			seg.modify(a,0,n,1,b);
		}else{
			cout<<seg.query(0,n,a,b,1)<<"\n";
		}
	}
	return 0;
}
