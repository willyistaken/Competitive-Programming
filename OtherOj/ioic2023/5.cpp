#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e6+5;

struct SEG{
	struct node{
		ll tag = 0;
		ll cnt = 0;
	} arr[4*N];

	void pull(int L,int R,int ind){
		if(arr[ind].tag){
			arr[ind].cnt = R-L;
		}else{
			if(R-L<=1){
				arr[ind].cnt=0;
				return ;
			}
			arr[ind].cnt = arr[2*ind].cnt+arr[2*ind+1].cnt;
		}
	}

	void modify(int l,int r,int L,int R,int ind,int v){
		if(l==L && r==R){
			arr[ind].tag+=v;
		}else{
			int M = (L+R)/2;	
			if(r<=M) modify(l,r,L,M,2*ind,v);
			else if(l>=M) modify(l,r,M,R,2*ind+1,v);
			else{
				modify(l,M,L,M,2*ind,v);
				modify(M,r,M,R,2*ind+1,v);
			}
		}
		pull(L,R,ind);
	}
	ll get(){
		return arr[1].cnt;
	}
};

struct line{
	int l;
	int r;
	int y;
	int v;
};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	vector<line> arr(2*n);
	for(int i=0;i<n;i++){
		cin>>arr[i].l>>arr[i].r;
		arr[i+n].l = arr[i].l;
		arr[i+n].r = arr[i].r;
		cin>>arr[i].y>>arr[i+n].y;
		arr[i].v = 1;
		arr[i+n].v = -1;
	}
	stable_sort(arr.begin(),arr.end(),[](const line &a,const line &b){return a.y<b.y;});
	ll sum = 0;
	int prev = 0;
	SEG seg;
	for(int i=0;i<2*n;i++){
		sum+=1LL*(arr[i].y-prev)*seg.get();
		prev = arr[i].y;
		seg.modify(arr[i].l,arr[i].r,0,N,1,arr[i].v);
	}
	cout<<sum<<"\n";
	return 0;
}
