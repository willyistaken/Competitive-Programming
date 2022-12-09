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
	BIT cnt;
	BIT sum;
	int n,k;cin>>n>>k;
	vector<int> arr(n);		
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<int> d=arr;
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=0;i<n;i++) arr[i] = lower_bound(d.begin(),d.end(),arr[i])-d.begin()+1;
	cnt.init(d.size());
	sum.init(d.size());
	for(int i=0;i<k-1;i++){
		cnt.modify(arr[i],1);
		sum.modify(arr[i],d[arr[i]-1]);
	}

	for(int i=k-1;i<n;i++){
		cnt.modify(arr[i],1);
		sum.modify(arr[i],d[arr[i]-1]);
		int l = 0;int r = d.size();	
		while(r-l>1){
			int m = (r+l)/2;
			if(cnt.query(m)>=(k/2)+(k%2)) r = m;
			else l = m;
		}
		ll fh = sum.query(r);
		ll sh = sum.query(d.size())-fh;
		ll ans = d[r-1]*cnt.query(r) - fh;
		ans+= sh - (d[r-1]*1LL*(k-cnt.query(r)));
		cout<<ans<<" \n"[i==n-1];
		cnt.modify(arr[i-k+1],-1);
		sum.modify(arr[i-k+1],-d[arr[i-k+1]-1]);
	}
	return 0;
}
