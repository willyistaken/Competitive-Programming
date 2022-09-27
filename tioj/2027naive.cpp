#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n;
struct seg{
	vector<int> arr;
	void init(){
		arr.resize(2*n,INT_MIN);
	}

	void change(int ind,int v){
		ind+=n;
		arr[ind]=v;
		ind>>=1;
		while(ind){
			arr[ind] = max(arr[2*ind],arr[2*ind+1]);	
			ind>>=1;
		}
	}

	int query(int l,int r){
		l+=n;r+=n;
		int ans = INT_MIN;
		while(l<r){
			if(l&1) ans = max(ans,arr[l++]);
			if(r&1) ans = max(ans,arr[--r]);
			l>>=1;r>>=1;
		}
		return ans;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	seg tre;
	tre.init();
	for(int i=0;i<n;i++) tre.change(i,arr[i]);
	ll ans=0;
	for(int l=0;l<n;l++){
		for(int r=l+1;r<n;r++){
			ans+=(arr[l]^arr[r])>=tre.query(l,r+1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
