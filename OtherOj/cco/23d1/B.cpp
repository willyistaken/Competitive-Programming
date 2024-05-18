#include<bits/stdc++.h>
using namespace std;
typedef long long llo;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e6+3;
/*
mantain a set of in process elements
repeatly remove elements from the leftmost or the rightmost side for which there doesn't exist a i<j<k such that hi>hj<hk
if(cnt>=2):
check for 4 number ll lr rl rr
some inequality
rl <= ll 
lr <= rr
pick the smallest of rl,lr M
than suppose the current height is h, and there are cnt element in my set
let L = (M-h)
ans+= L(ll+M+rr+2*cnt-3)+(3*cnt-4)*(L*(h+M-1))/2;
h = M;

else:
find 2 numbers l, r
WLOG l<=r
ans += (h+l-1)(l-h)/2 + (l+r)(l-h)
*/

struct SEG{
	vector<int> arr;
	int n;
	void init(int _n){
		n = _n;	
		arr.resize(4*n,0);
	}
	void modify(int x,int v,int L,int R,int ind){
		if(R==L){
			arr[ind]=v;
			return;
		}
		int M = (L+R)/2;
		if(x<=M) modify(x,v,L,M,2*ind);
		else modify(x,v,M+1,R,2*ind+1);
		arr[ind] = min(arr[2*ind],arr[2*ind+1]);
	}
	int query(int l,int r,int L,int R,int ind){
		if(l==L && r==R) return arr[ind];
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		if(l>M) return query(l,r,M+1,R,2*ind+1);
		return min(query(l,M,L,M,2*ind),query(M+1,r,M+1,R,2*ind+1));
	}
} seg;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	seg.init(n);
	vector<int> h(n);
	vector<int> d;
	for(int i=0;i<n;i++){
		cin>>h[i];
		seg.modify(i,h[i],0,n-1,1);
		d.push_back(h[i]);
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	vector<vector<int> > V(d.size());	
	for(int i=0;i<n;i++){
		int l = lower_bound(d.begin(),d.end(),h[i])	-d.begin();
		V[l].push_back(i);
	}
	llo ans = 0;
	set<int> s;
	for(int F=0;F<d.size();F++){
		for(auto i : V[F]){
			s.insert(i);
			seg.modify(i,1e9+5,0,n-1,1);
		}
		int H = d[F];
		while(s.size()){
			int cur = *s.begin();
			int l = seg.query(0,cur,0,n-1,1);
			int r = seg.query(cur,n-1,0,n-1,1);
			if((l>1e9 || l<=H) || (r>1e9 || r<=H)){
				s.erase(cur);
			}
			else break;
		}
		while(s.size()){
			int cur = *s.rbegin();
			int l = seg.query(0,cur,0,n-1,1);
			int r = seg.query(cur,n-1,0,n-1,1);
			if((l>1e9 || l<=H) || (r>1e9 || r<=H)){
				s.erase(cur);
			}
			else break;
		}
		if(s.size()==1){
			int cur = *s.begin();
			int l = seg.query(0,cur,0,n-1,1);
			int r = seg.query(cur,n-1,0,n-1,1);
			if(l>r)	swap(l,r);
			ans = ((ans+(1LL*(H+l-1)*(l-H)/2)%MOD)%MOD + ((1LL*(l+r)*(l-H))%MOD))%MOD;
		}else if(s.size()>1){
			int cnt = s.size();
			int ll = seg.query(0,*s.begin(),0,n-1,1);
			int lr = seg.query(*s.begin(),n-1,0,n-1,1);
			int rl = seg.query(0,*(s.rbegin()),0,n-1,1);
			int rr = seg.query(*(s.rbegin()),n-1,0,n-1,1);
			int M = min(lr,rl);
			int hsum = (1LL*(M+H-1)*(M-H)/2)%MOD;
			int A = (3LL*(cnt-1))%MOD;
			int B = ((2*(cnt-2))+1+ll)%MOD+rr%MOD+M%MOD;
			ans=(1LL*B*(M-H)%MOD+ans)%MOD;
			ans=(ans+(1LL*A*hsum)%MOD)%MOD;
		}
	}
	ans%=MOD;
	if(ans<0) ans+=MOD;
	cout<<ans<<"\n";
	
	return 0;
}
