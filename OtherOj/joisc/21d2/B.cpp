#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define x first
#define y second
struct bit{
	vector<int> arr;
	int n;
	void init(int _n){
		arr.resize(_n+1,0);
		n = _n;
	}
	void modify(int ind,int v){
		while(ind<=n){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		int ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind&-ind);
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int k;cin>>k;
	pair<ll,ll> arr[n];
	for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
	for(int i=0;i<n;i++){
		arr[i].x = arr[i].x+arr[i].y;
		arr[i].y = arr[i].x-2*arr[i].y;
	}
	sort(arr,arr+n);
	vector<ll> d;
	for(int i=0;i<n;i++) d.push_back(arr[i].y);
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	bit B;
	B.init(d.size());
	ll l = 0;
	ll r = 1e10;
	while(r-l>1){
		ll mid = (l+r)/2;
		ll cnt = 0;
		int head = 0;
		B.modify(lower_bound(d.begin(),d.end(),arr[0].y)-d.begin()+1,1);
		for(int i=1;i<n;i++){
			while(head<i && arr[head].x<arr[i].x-mid){
				B.modify(lower_bound(d.begin(),d.end(),arr[head].y)-d.begin()+1,-1);
				head++;
			}
			int qr = upper_bound(d.begin(),d.end(),arr[i].y+mid)-d.begin();
			int ql = lower_bound(d.begin(),d.end(),arr[i].y-mid)-d.begin()+1;
			cnt+=B.query(qr)-B.query(ql-1);
			B.modify(lower_bound(d.begin(),d.end(),arr[i].y)-d.begin()+1,1);
		}
		fill(B.arr.begin(),B.arr.end(),0);
		if(cnt>=k) r = mid;
		else l = mid;
	}
	vector<ll> ans;
	set<pair<ll,ll> > s;
	s.insert(make_pair(arr[0].y,0));
	int head = 0;
	for(int i=1;i<n;i++)	{
		while(head<i && arr[head].x<arr[i].x-l){
			auto it = s.find(make_pair(arr[head].y,head));
			s.erase(it);
			head++;
		}
		auto it = s.upper_bound(make_pair(arr[i].y-l,-1));	
		for(;it!=s.end() && it->first<=arr[i].y+l; ++it){
			int j = it->second;
			ans.push_back(max(abs(arr[i].x-arr[j].x),abs(arr[i].y-arr[j].y)));
		}
		s.insert(make_pair(arr[i].y,i));
	}
	sort(ans.begin(),ans.end());
	assert(ans.size()<=k);
	int left = k-ans.size();
	for(auto i : ans) cout<<i<<"\n";
	for(int i=0;i<left;i++) cout<<r<<"\n";
	return 0;
}
