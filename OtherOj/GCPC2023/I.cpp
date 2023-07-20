#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll


struct BIT{
	vector<int> arr;
	void init(int s){
		arr.assign(s+1,0);
	}
	void add(int ind,int v){
		while(ind<arr.size()){
			arr[ind]+=v;
			ind +=(ind&-ind);
		}
	}
	int query(int ind){
		int ans=0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind&-ind);
		}
		return ans;
	}
} bit;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	bit.init(2e6);
	vector<int> pos(n+1,0);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		pos[i]=k;
		bit.add(k,1);
	}
	int q;cin>>q;
	while(q--){
		int a;cin>>a;
		int p = pos[a];
		int l = p;int r = 2e6;
		while(r-l>1){
			int mid = (l+r)/2;
			if(bit.query(mid)-bit.query(p)==mid-p) l = mid;
			else r = mid;
		}
		cout<<r<<"\n";
		bit.add(p,-1);
		bit.add(r,1);
		pos[a]=r;
	}
	return 0;
}
