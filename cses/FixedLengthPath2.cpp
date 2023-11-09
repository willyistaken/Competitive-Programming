#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct BIT{
	vector<ll> arr;
	int _n;
	void init(int s){
		arr.resize(s+1,0);
		_n = s;
	}
	void modify(int ind,int v){
		while(ind<=_n){
			arr[ind]+=v;
			ind+=(ind & -ind);
		}
	}
	ll query(int ind){
		if(ind<=0) return 0;
		ll ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}

} bit;

const int N = 2e5+5;
bool pick[N];
int sz[N];

int k1,k2;
vector<int> side[N];
ll get(int v,int p=0,int dep=1){
	if(dep>k2+5) return 0;
	ll ans = 0;
	ans+=(bit.query(k2-dep)-bit.query(k1-dep-1));
	for(auto i : side[v]){
		if(!pick[i] && i!=p){
			ans += get(i,v,dep+1);		
		}
	}
	return ans;
}

ll fill(int v,int p=0,int dep=1){
	if(dep>k2+5) return 0;
	ll maxn = dep;
	bit.modify(dep,1);
	for(auto i : side[v]){
		if(!pick[i] && i!=p){
			maxn = max(maxn,fill(i,v,dep+1));
		}
	}
	return maxn;
}

int getsz(int v,int p=0){
	sz[v]=1;
	for(auto i : side[v]){
		if(!pick[i] && i!=p){
			sz[v]+=getsz(i,v);
		}
	}
	return sz[v];
}

int centroid(int ds,int v,int p=0){
	for(auto i : side[v]) if(!pick[i] && i!=p && sz[i]>ds) return centroid(ds,i,v);
	return v;
}
ll ans(int v){
	int g = centroid(getsz(v)/2,v);	
	pick[g]=1;
	ll r = 0;
	ll m = 0;
	for(auto i : side[g]){
		if(!pick[i]){
			r+=get(i,g);
			m = max(m,fill(i,g));
		}
	}
	r+=bit.query(k2)-bit.query(k1-1);
	for(int i=1;i<=m+1;i++) bit.modify(i,bit.query(i-1)-bit.query(i));
	for(auto i : side[g]){
		if(!pick[i]) r+=ans(i);
	}
	return r;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n>>k1>>k2;
	bit.init(n+5);
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	cout<<ans(1)<<"\n";
	return 0;
}
