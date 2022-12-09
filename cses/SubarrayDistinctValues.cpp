#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct BIT{
	vector<int> arr;
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

	int query(int ind){
		if(ind==0) return 1e9;
		int ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}

};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	BIT bit;
	int n;cin>>n;
	bit.init(n);
	int k;cin>>k;
	int prev[n+1];	
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	map<int,int> loc;
	for(int i=1;i<=n;i++){
		prev[i] = loc[arr[i]];
		loc[arr[i]] = i;
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		bit.modify(prev[i]+1,1);
		bit.modify(i+1,-1);
		int l = 0;int  r = i;
		while(r-l>1){
			int m = (r+l)/2;
			if(bit.query(m)>k) l = m;
			else r = m;	
		}
		ans+=(i-r+1);	
	}
	cout<<ans<<"\n";
	return 0;
}
