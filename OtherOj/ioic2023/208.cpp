#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct bit{
	vector<ll> arr;
	int n;
	void init(int s){
		arr.resize(s+1,0);
		n = s;
	}
	void add(int i,ll v){
		while(i<=n){
			arr[i]+=v;
			i+=(i&-i);
		}
	}

	ll query(int i){
		ll sum = 0;
		while(i){
			sum+=arr[i];
			i-=(i&-i);
		}
		return sum;
	}
};

bit b1;
bit b2;

void radd(int l,int r,ll v){
	b1.add(l,v);
	b1.add(r+1,-v);
	b2.add(l,l*(-v));
	b2.add(r+1,(r+1)*(v));
}

ll rquery(int l,int r){
	ll s = b1.query(r)-b1.query(l-1);
	ll st = b2.query(r)-b2.query(l-1);
	ll ans = (r+1)*s+st;
	ans+=(r-l+1)*b1.query(l-1);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;	
	b1.init(n);
	b2.init(n);
	for(int i=0;i<n;i++){
		int a;cin>>a;
		radd(i+1,i+1,a);
	}
	while(q--){
		int type;cin>>type;
		if(type==1){
			int l,r,d;cin>>l>>r>>d;
			radd(l,r,d);
		}else{
			int l,r;cin>>l>>r;
			cout<<rquery(l,r)<<"\n";
		}
	}
	return 0;
}
