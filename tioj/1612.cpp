#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct p{
	ll x;
	ll v;
};
int n,k;
ll x,D;
struct seg{
	vector<ll> arr;
	void init(){
		arr.resize(2*n+2);	
		fill(arr.begin(),arr.end(),LONG_LONG_MIN);
	}
	void change(int ind,ll v){
		ind+=n+1;
		if(arr[ind]>v) return;
		arr[ind]=v;
		ind>>=1;
		while(ind){
			arr[ind] = max(arr[2*ind],arr[2*ind+1]);	
			ind>>=1;
		}
	}
	ll query(int l,int r){
		l+=n+1;r+=n+1;
		ll result = LONG_LONG_MIN;
		while(l<r){
			if(l%2) result = max(result,arr[l++]);
			if(r%2) result = max(result,arr[--r]);
			l>>=1;r>>=1;
		}
		return result;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k>>x>>D;
	seg dp;
	p arr[n+1];
	dp.init();
	dp.change(0,0);
	for(int i=1;i<=n;i++){
		cin>>arr[i].x>>arr[i].v;
	}
	arr[0].x=0;arr[0].v=0;
	sort(arr,arr+n+1,[](const p &a,const p &b){return a.x<b.x;});
	for(int i=1;i<=k;i++){
		for(int j=n;j>=1;j--){
			int l=-1;int r=j-1;	
			while(r-l>1){
				int mid = (r+l)/2;
				if(arr[mid].x+D>=arr[j].x) r=mid;
				else l=mid;
			}
			ll maxn = dp.query(r,j);
			dp.change(j,maxn+arr[j].v);
		}
	}
	cout<<dp.query(0,n+1)<<"\n";




	return 0;
}

// I know this can be done using deque, but I am too lazy to think about it.
