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
	int n,k;cin>>n>>k;	
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	vector<int> d = arr;
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=0;i<n;i++) arr[i] = lower_bound(d.begin(),d.end(),arr[i])-d.begin()+1;

	BIT bit;
	bit.init(d.size());
	
	for(int i=0;i<k-1;i++){
		bit.modify(arr[i],1);	
	}
	for(int i=k-1;i<n;i++){
		bit.modify(arr[i],1);
		int l = 0;int r = d.size();
		while(r-l>1){
			int m = (r+l)/2;
			if(bit.query(m)>=(k/2)+(k%2)) r = m;
			else l = m;
		}
		cout<<d[r-1]<<" \n"[i==n-1];
		bit.modify(arr[i-k+1],-1);
	}
	

	return 0;
}
