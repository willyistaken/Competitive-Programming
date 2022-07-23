#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



struct bit{
	vector<int> arr;
	int size=0;
	void init(int s){
		arr.resize(s+1,0);
		size = s;
	}
	void add(int ind){
		while(ind<=size){
			arr[ind]+=1;
			ind+=(ind & -ind);
		}
	}
	int query(int ind){
		int r = 0;
		while(ind){
			r+=arr[ind];
			ind-=(ind & -ind);
		}
		return r;
	}
	void clear(){
		fill(arr.begin(),arr.end(),0);
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+1]={0};
		int bound[n]={0};
		for(int i=1;i<=n;i++) {
			cin>>arr[i];
			bound[i-1]=arr[i];
		}
		sort(bound,bound+n);
		bit fenwick;
		fenwick.init(n);
		int rless[n+1]={0};
		int lless[n+1]={0};
		for(int i=1;i<=n;i++){
			int loc =	upper_bound(bound,bound+n,arr[i])-bound;	
			lless[i] = fenwick.query(loc);
			fenwick.add(loc);
		}
		fenwick.clear();
		for(int i=n;i>=1;i--){
			int loc = upper_bound(bound,bound+n,arr[i])-bound;
			rless[i] = fenwick.query(loc);
			fenwick.add(loc);
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans += 1LL*lless[i]*(n-i - rless[i]);
			ans += 1LL*(i-1-lless[i])*(rless[i]);
		}
		cout<<ans<<"\n";
	}

	return 0;
}
