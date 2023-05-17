#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct LiChao{
	struct line{
		ll m = 0;
		ll b = 0;
		bool empty = 1;
		ll operator()(ll x){
			if(empty) return 1e18;
			return m*x+b;
		}
	};
	vector<line> arr;
	void init(int s){
		arr.resize(4*s);		
	}
	
	void insert(line seg,int L,int R,int arri){
		if(arr[arri].empty){
			arr[arri] = seg;
			return ;
		}
		if(R-L==1){
			if(seg(L)<arr[arri](L))	arr[arri] = seg;
			return ;
		}
		int M = (L+R)/2;
		if(arr[arri].m<seg.m) swap(arr[arri],seg);
		if(arr[arri](M)>seg(M)){
			swap(arr[arri],seg);	
			insert(seg,L,M,2*arri);
		}else{
			insert(seg,M,R,2*arri+1);
		}
	}

	ll query(int x,int L,int R,int arri){
		if(x==L && R-L==1) return arr[arri](x);
		int M = (R+L)/2;
		if(x<M) return min(arr[arri](x),query(x,L,M,2*arri));
		else return min(arr[arri](x),query(x,M,R,2*arri+1));
	}
};
