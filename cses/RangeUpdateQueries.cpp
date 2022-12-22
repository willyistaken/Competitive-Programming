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
		ll ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}

};



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	BIT bit;
	bit.init(n);
	for(int i=1;i<=n;i++){
		ll a;cin>>a;
		ll q = bit.query(n);
		bit.modify(i,a-q);
	}
	while(q--){
		int t;cin>>t;
		if(t==2){
			int a;cin>>a;
			cout<<bit.query(a)<<"\n";
		}else{
			int l,r;cin>>l>>r;
			ll v;cin>>v;
			bit.modify(l,v);
			bit.modify(r+1,-v);
		}
	}
	return 0;
}
