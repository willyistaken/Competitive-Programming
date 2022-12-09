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
	void modify(int ind,ll v){
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
		int a;cin>>a;
		bit.modify(i,a);
	}
	while(q--){
		int t;cin>>t;
		int a,b;cin>>a>>b;
		if(t==2){
			cout<<bit.query(b)-bit.query(a-1)<<"\n";
		}else{
			ll og = bit.query(a)-bit.query(a-1);
			bit.modify(a,-og);
			bit.modify(a,b);
		}
	}
	return 0;
}
