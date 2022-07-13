#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,e;
vector<ll> cc;
struct bit{
	vector<int> arr;
	void init(){
		arr.resize(e+1);
		fill(arr.begin(),arr.end(),0);
	}
	void add(int ind){
		while(ind<=e){
			arr[ind]+=1;
			ind+=(ind & -ind);
		}
	}

	int query(int ind){
		int r=0;
		while(ind){
			r+=arr[ind];
			ind -= (ind & -ind);
		}
		return r;
	}
};








bool check(ll v,ll sum[]){
	bit fenwick;
	fenwick.init();
	int howmany=0;
	for(int i=0;i<=n;i++){
		int g = lower_bound(cc.begin(),cc.begin()+e,sum[i]-v)-cc.begin();
		int kg = upper_bound(cc.begin(),cc.begin()+e,sum[i])-cc.begin();
		//for(auto i : fenwick.arr) cout<<i<<" ";
		//cout<<"\n";
		howmany+=fenwick.query(g);	
		fenwick.add(kg);
	}
	if(howmany<k) return true;
	else return false;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n>>k &&(n||k)){
		cc.clear();
		cc.push_back(0);
		ll sum[n+1]={0};
		ll maxnnow=-1e15;
		ll minnow=1e15;
		ll r=maxnnow;
		ll l = minnow;
		for(int i=1;i<=n;i++){
			int a;cin>>a;
			maxnnow = max(maxnnow+a,1LL*a);
			minnow = min(minnow+a,1LL*a);
			r = max(r,maxnnow);
			l = min(l,minnow);
			sum[i] = sum[i-1]+a;
			cc.push_back(sum[i]);
		}
		l--;
		sort(cc.begin(),cc.end());
		e =unique(cc.begin(),cc.end())-cc.begin();
		//for(int i=0;i<e;i++) cout<<cc[i]<<" ";
		//cout<<"\n";
		while(r-l>1){
			int mid = l + ((r-l)/2);
			if(check(mid,sum)){
				r = mid;
			}else{
				l=mid;
			}
		}
		cout<<r<<"\n";
	}	
	return 0;
}
