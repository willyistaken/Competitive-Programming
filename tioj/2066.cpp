#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n;int NS;
const ll MOD = (1UL<<61)-1;
struct bit{
	vector<ll> arr;
	bit(){
		arr.resize(NS+1);
		fill(arr.begin(),arr.end(),0);
	}

	void add(int ind,ll v){
		while(ind<=NS){
			arr[ind]+=v;
			arr[ind]%=MOD;
			ind+= (ind & -ind);
		}
	}
	ll query(int ind){
		ll r=0;
		while(ind){
			r+=arr[ind];
			r%=MOD;
			ind-=(ind & -ind);
		}
		return r;
	}
	void clean(){
		fill(arr.begin(),arr.end(),0);
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int k;cin>>n>>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		vector<int> d = arr;
		sort(d.begin(),d.end());
		d.resize(unique(d.begin(),d.end())-d.begin());
		for(int i=0;i<n;i++){
			arr[i] = lower_bound(d.begin(),d.end(),arr[i])-d.begin()+1;
		}
		NS = d.size();
		bit fenwick;
		ll  tobe[n];
		fill(tobe,tobe+n,1);
		ll ans=n;
		for(int j=2;j<=k;j++){
			fenwick.clean();
			for(int i=0;i<n;i++){
				fenwick.add(arr[i],tobe[i]);
				tobe[i] = fenwick.query(arr[i]-1);
				ans+=tobe[i];
				ans%=MOD;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}
