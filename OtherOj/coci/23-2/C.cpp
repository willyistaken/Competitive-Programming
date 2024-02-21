#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds


// num = the suffix minnimum sequence , smaller than me count + n
// first get the range of time that stuff is the min
// set+bit to maintain some suffix min;
int n,q;
struct SGT{
	vector<int> arr;
	void init(){
		arr.resize(4*n,0);
	}
	void modify(int x,int v,int l=1,int r=n,int ind=1){
		if(l==r){
			arr[ind]=v;
			return ;
		}
		int m =  (l+r)/2;
		if(x<=m) modify(x,v,l,m,2*ind);
		else modify(x,v,m+1,r,2*ind+1);
		arr[ind] = max(arr[2*ind],arr[2*ind+1]);
	}
	int query(int l,int r,int L=1,int R=n,int ind=1){
		if(L==l && R==r){
			return arr[ind];
		}
		int M = (L+R)/2;
		if(r<=M) return query(l,r,L,M,2*ind);
		if(l>M) return query(l,r,M+1,R,2*ind+1);
		return max(query(l,M,L,M,2*ind),query(M+1,r,M+1,R,2*ind+1));
	}
};

struct BIT{
	vector<int> arr;
	void init(){
		arr.resize(n+1);
	}
	void add(int ind,int v){
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		int r = 0;
		while(ind){
			r+=arr[ind];
			ind-=(ind&-ind);
		}
		return r;
	}
};

set<int> sufmin;


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	vector<int> arr(n+1);
	vector<int> pos(n+1);
	vector<int> exit(n+1);
	vector<int> kick(q+1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		pos[arr[i]]=i;
		exit[arr[i]]=n+1;
	}
	for(int i=1;i<=q;i++){
		cin>>kick[i];
		exit[arr[kick[i]]]=i;
	}
	vector<vector<int> > addsuf(n+1);
	vector<vector<int> > remsuf(n+1);
	SGT seg;seg.init();
	for(int i=1;i<=n;i++){
		int l = pos[i];
		int a = seg.query(l,n);
		if((a)>exit[i]-1) continue;
		addsuf[a].push_back(i);
		remsuf[exit[i]-1].push_back(i);
		seg.modify(pos[i],exit[i]);
	}
	// finish get sufmin
	BIT val,ind,insuf;
	val.init();
	ind.init();
	insuf.init();
	for(int i=1;i<=n;i++){
		val.add(i,1);
		ind.add(pos[i],1);
	}
	ll ans = 0;
	for(int i=0;i<=q;i++){
		for(auto e :addsuf[i]){
			if(exit[e]<i) continue;
			ans+=ind.query(pos[e])-val.query(e);
			sufmin.insert(e);
			insuf.add(pos[e],1);
		}
		if(i!=0){
			int u = arr[kick[i]];
			if(!sufmin.count(u)){
				int L = insuf.query(pos[u]);
				auto k = sufmin.lower_bound(u);
				--k;
				int R = insuf.query(pos[(*k)]);
				ans-=max(0LL,R-L);
			}else{
				ans-=ind.query(pos[u])-val.query(u);
				sufmin.erase(u);
				insuf.add(pos[u],-1);
			}
			ind.add(pos[u],-1);
			val.add(u,-1);
		}
		cout<<ans+n-i<<" ";
	}
	cout<<"\n";
	return 0;
}


