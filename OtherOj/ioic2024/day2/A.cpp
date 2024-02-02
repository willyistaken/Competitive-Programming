#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct BIT{
	vector<ll> arr;
	int n;
	void init(int _n){
		n = _n;	
		arr.resize(n+1,0);
	}
	void add(ll v,int ind){
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}

	}
	ll query(int ind){
		ll sum=0;
		while(ind){
			sum+=arr[ind];
			ind-=(ind&-ind);
		}
		return sum;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	BIT sum;
	BIT sum2;
	int n;cin>>n;
	sum.init(n);
	sum2.init(n);
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		sum.add(a,i);
		sum2.add(a*a,i);
	}
	int q;cin>>q;
	while(q--){
		int t;cin>>t;
		if(t==2){
			int l,r;cin>>l>>r;
			ll ans = sum.query(r)-sum.query(l-1);
			ans = ans*ans;
			ans-=sum2.query(r)-sum2.query(l-1);
			cout<<ans/2<<"\n";
		}
		else{
			int p,x;cin>>x>>p;
			ll dif = sum.query(x)-sum.query(x-1);
			sum.add(-dif,x);
			dif = sum2.query(x)-sum2.query(x-1);
			sum2.add(-dif,x);
			sum.add(p,x);
			sum2.add(p*p,x);
		}
	}
	return 0;
}
