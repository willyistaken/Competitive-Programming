#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;
vector<int> h;
namespace GET{
	const int B = 20;
	vector<int> st[B];
	void init_get(){
		for(int i=0;i<B;i++) st[i].resize(n+1);
		for(int i=1;i<=n;i++) st[0][i]=h[i];
		for(int j=1;j<B;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				st[j][i] = max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			}
		}
	}
	int minn(int l,int r){
		if(l==r) return st[0][l];
		int len = (r-l+1);
		int p = __lg(len);
		return max(st[p][l],st[p][r-(1<<p)+1]);
	}
	pair<int,int> get(int x,int h){
		int rl,rr;
		rl=0;rr=0;
		int l = x;int r = n+1;		
		while(r-l>1){
			int m = (l+r)/2;
			if(minn(x,m)>=h) r = m;
			else l = m;
		}
		rr = l;
		l = 0;r = x;
		while(r-l>1){
			int m = (l+r)/2;
			if(minn(m,x)>=h) l = m;
			else r = m;
		}
		rl = r;
		return {rl,rr};
	}
} 

struct p_range{
	int x;
	bool y;
	pair<int,int> r;
	int cost;
	ll dp;
};

struct BIT{
	int n;
	vector<ll> arr;
	void init(int _n){
		n = _n;
		arr.resize(n+1,0);
	}
	void add(int x,ll v){
		while(x<=n){
			arr[x]+=v;
			x+=(x&-x);
		}
	}
	void modify(int l,int r,ll v){
		if(l>r) return;
		add(l,v);
		add(r+1,-v);
	}
	ll query(int x){
		ll r=0;
		while(x){
			r+=arr[x];
			x-=(x&-x);
		}
		return r;
	}
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;	
	h.resize(n+1);
	for(int i=1;i<=n;i++) cin>>h[i];
	GET::init_get();
	int m;cin>>m;
	vector<p_range> stars(m+1);			
	ll ans = 0;
	for(int i=0;i<m;i++){
		cin>>stars[i].x>>stars[i].y;
		cin>>stars[i].cost;
		stars[i].r  = GET::get(stars[i].x,stars[i].y);
		ans+=stars[i].cost;
	}
	stars[m].x=1;
	stars[m].y=n+1;
	stars[m].r = GET::get(1,n+1);
	stars[m].cost=0;
	sort(stars.begin(),stars.end(),[](const p_range &a,const p_range &b){return a.y<b.y;});
	set<pair<int,int> > rgs;	
	BIT bit;	
	bit.init(n);
	for(int i=0;i<=m;i++){
		ll sum=0;
		vector<int> k;
		while(rgs.size()){
			auto f = rgs.lower_bound({stars[i].r.first,-1});
			if(f==rgs.end() || f->first>stars[i].r.second) break;
			k.push_back(f->second);
			rgs.erase(f);
		}
		for(auto g : k){
			sum+=stars[g].dp;
		}
		bit.modify(stars[i].r.first,stars[i].r.second,sum);
		for(auto g : k){
			bit.modify(stars[g].r.first,stars[g].r.second,-stars[g].dp);
		}
		stars[i].dp = max(sum,bit.query(stars[i].x)+stars[i].cost);
		rgs.insert({stars[i].r.first,i});
	}
	cout<<ans-stars[m].dp<<"\n";
	return 0;
}
