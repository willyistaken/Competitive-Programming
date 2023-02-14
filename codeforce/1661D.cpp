#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct bit{
	vector<ll> arr;
	int s;
	void init(int n){
		arr.resize(n+1,0);
		s = n;
	}
	void modify(int x,ll v){
		while(x<=s){
			arr[x]+=v;
			x+=(x&-x);
		}
	}
	ll query(int x){
		ll sum= 0;
		while(x){
			sum+=arr[x];
			x-=(x&-x);
		}
		return sum;
	}
};

bit b,bb;
ll ans = 0;
void add(int l,int r,ll x){
	ans+=x;
	b.modify(l,x);
	b.modify(r+1,-x);
	bb.modify(l,-1LL*l*x);
	bb.modify(r+1,1LL*(r+1)*x);
}

ll query(int x){
	ll a =  bb.query(x);
	ll s = b.query(x);
	s*=(x+1);
	return s+a;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	b.init(n);
	bb.init(n);
	ll arr[n+1];	
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=n;i>k;i--){
		ll g = max(arr[i]-query(i),0LL);
		ll m = (g/k)+(g%k!=0);
		add(i-k+1,i,m);	
	}
	ll maxnu = 0;
	for(ll i=1;i<=k;i++){
		ll g = max(arr[i]-query(i),0LL);		
		ll m = (g/i) + (g%i!=0);
		maxnu = max(m,maxnu);
	}
	cout<<ans+maxnu<<"\n";
	return 0;
}
