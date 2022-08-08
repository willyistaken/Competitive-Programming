#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pdbs::;

int n;
ll k;
vector<ll> arr;
vector<ll> sorted;
bool works(ll g){
	ll ans=0;
	for(int i=0;i<n;i++){
		ll low = arr[i]-g;
		ll	high = arr[i]+g; 
		int range = upper_bound(sorted.begin(),sorted.end(),high) - lower_bound(sorted.begin(),sorted.end(),low);
		ans+= range-1;
	}
	ans>>=1;
	return ans>=k;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sorted.push_back(arr[i]);
	}
	sort(sorted.begin(),sorted.end());
	ll l=0;
	ll r = sorted.back()-sorted.front();		
	while(r-l>1){
		ll mid=l+((r-l)>>1);
		if(works(mid)) r =mid;
		else l = mid;
	}
	cout<<r<<"\n";

	return 0;
}
