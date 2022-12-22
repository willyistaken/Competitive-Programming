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
	int n;cin>>n;
	BIT bit;
	bit.init(n);
	int arr[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<=n;i++) bit.modify(i,1);
	for(int i=0;i<n;i++){
		int a;cin>>a;
		int l = 0;int r = n;
		while(r-l>1){
			int m = (r+l)/2;
			if(bit.query(m)>=a) r= m;
			else l = m;
		}
		bit.modify(r,-1);
		cout<<arr[r]<<' ';
	}
	cout<<"\n";
	return 0;
}
