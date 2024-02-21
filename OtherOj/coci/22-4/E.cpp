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
	void add(int ind,ll v){
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	ll query(int ind){
		ll r = 0;
		while(ind){
			r +=arr[ind];
			ind-=(ind&-ind);
		}
		return r;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pair<int,int> > q(n);
	vector<int> d;
	BIT b;
	for(int i=0;i<n;i++){
		cin>>q[i].first>>q[i].second;
		d.push_back(q[i].first);
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=0;i<n;i++){
		q[i].first = lower_bound(d.begin(),d.end(),q[i].first)-d.begin()+1;
	}
	b.init(d.size());
	ll cur = 0;
	for(int i=0;i<n;i++){
		b.add(q[i].first,q[i].second);
		cur+=q[i].second;
		int l = 0;int r = d.size()+1;
		while(r-l>1){
			int m = (l+r)/2;
			if(b.query(m)>=((cur+1)/2)) r = m;
			else l = m;
		}
		cout<<d[r-1]<<"\n";
	}
	return 0;
}
