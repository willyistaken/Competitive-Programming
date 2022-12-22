#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,m;

struct SEG{
	vector<int> arr;
	void init(){
		arr.resize(4*n,0);
	}
	void modify(int ind,int v,int L,int R,int arri){
			if(L==ind && R-L==1){
				arr[arri] = v;
				return ;
			}
			int M = (R+L)/2;
			if(ind<M) modify(ind,v,L,M,2*arri);
			else if(ind>=M) modify(ind,v,M,R,2*arri+1);
			arr[arri] = max(arr[2*arri],arr[2*arri+1]);
	}
	int query(int l,int r,int L,int R,int arri){
		if(l==L && r==R) return arr[arri];
		int M = (R+L)/2;
		if(r<=M) return query(l,r,L,M,2*arri);
		else if(l>=M) return query(l,r,M,R,2*arri+1);
		else{
			return max(query(l,M,L,M,2*arri),query(M,r,M,R,2*arri+1));
		}
	}
} seg;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	seg.init();
	for(int i=0;i<n;i++){
		int a;cin>>a;
		seg.modify(i,a,0,n,1);
	}
	for(int i=0;i<m;i++){
		int a;cin>>a;
		if(seg.query(0,n,0,n,1)<a) {
			 cout<<0<<" ";
			continue;
		}
		int l = 0;int r = n;
		while(r-l>1){
			int mid = (r+l)/2;
			//cout<<mid<<' '<<seg.query(0,mid,0,n,1)<<"\n";	
			if(seg.query(0,mid,0,n,1)>=a) r = mid;
			else l = mid;
		}
		int v = seg.query(0,r,0,n,1);
		cout<<r<<" ";
		seg.modify(r-1,v-a,0,n,1);
	}
	cout<<"\n";
	return 0;
}
