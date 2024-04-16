#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct PSEG{
	struct node{
		ll sum=0;
		int cnt=0;	
		int lc=0;
		int rc=0;
		int l=0;
		int r=0;
	};
	vector<node> arr;
	vector<int> root;
	int built(int l,int r){
		node k;
		k.l=l;k.r=r;
		arr.push_back(k);
		int c = arr.size()-1;
		if(l==r) return c;
		int m = (l+r)/2;
		arr[c].lc = built(l,m);
		arr[c].rc = built(m+1,r);
		return c;
	}
	int modify(int ind,int v,int cur){
		node k = arr[cur];
		if(arr[cur].l==arr[cur].r){
			k.sum+=v;
			k.cnt+=1;
			arr.push_back(k);
			return arr.size()-1;
		}
		if(ind<=arr[arr[cur].lc].r){
			k.lc = modify(ind,v,arr[cur].lc);
		}else{
			k.rc = modify(ind,v,arr[cur].rc);
		}
		k.sum = arr[k.lc].sum+arr[k.rc].sum;
		k.cnt = arr[k.lc].cnt+arr[k.rc].cnt;
		arr.push_back(k);
		return arr.size()-1;
	}
	void newstuff(int ind,int v){
		root.push_back(modify(ind,v,root.back()));
	}
	ll get(int lnode,int rnode,int k){
		if(k==0) return 0;
		if(arr[rnode].lc==0){
			return arr[rnode].sum-arr[lnode].sum;
		}
		ll cnts = arr[arr[rnode].lc].cnt-arr[arr[lnode].lc].cnt;
		ll sums = arr[arr[rnode].lc].sum-arr[arr[lnode].lc].sum;
		if(cnts<=k) return sums+get(arr[lnode].rc,arr[rnode].rc,k-cnts);
		else return get(arr[lnode].lc,arr[rnode].lc,k);
	}
	void init(int n,vector<int> &a){
		arr.push_back(node());
		root.push_back(built(1,n));
		vector<int> d;
		for(int i=1;i<=n;i++) d.push_back(a[i]);
		sort(d.begin(),d.end());
		d.resize(unique(d.begin(),d.end())-d.begin());
		for(int i=1;i<=n;i++){
			int k = lower_bound(d.begin(),d.end(),a[i])-d.begin()+1;
			newstuff(k,min(0,a[i]));
		}
	}
	void print(int cur){
		if(!cur) return;
		print(arr[cur].lc);
		print(arr[cur].rc);
	}
} seg;

int n,k;
vector<int> arr;
vector<ll> Sum;
vector<ll> noNsum;


ll cost(int l,int r){
	l--;
	ll S = Sum[r]-Sum[l];
	int lnode = seg.root[l];
	int rnode = seg.root[r];
	if(seg.arr[rnode].cnt-seg.arr[lnode].cnt<=k){
		return S-(noNsum[r]-noNsum[l]);
	}else{
		ll f = S-seg.get(lnode,rnode,k);
		return f;
	}
}

vector<ll> ans;

void calc(int l,int r,int fl,int fr){
	if(l>r) return;
	if(fl==fr){
		for(int i=l;i<=r;i++){
			ans[i] = cost(fl,i);
		}
	}
	int m = (l+r)/2;
	pair<ll,int> maxn= {cost(fl,m),fl};	
	for(int i=fl+1;i<=fr;i++){
		if(i>m) break;
		maxn = max(maxn,{cost(i,m),i});
	}
	ans[m] = maxn.first;
	calc(l,m-1,fl,maxn.second);
	calc(m+1,r,maxn.second,fr);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;	
	arr.resize(n+1,0);
	Sum.resize(n+1,0);
	noNsum.resize(n+1,0);
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++) Sum[i]=Sum[i-1]+arr[i];
	for(int i=1;i<=n;i++) noNsum[i]=noNsum[i-1]+min(arr[i],0);
	seg.init(n,arr);
	ans.resize(n+1);
	calc(1,n,1,n);
	ll rans=0;
	for(int i=1;i<=n;i++) rans=  max(rans,ans[i]);
	cout<<rans<<"\n";
	return 0;
}
