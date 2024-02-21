#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int n,k;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	vector<int> arr(n+1);
	vector<ll> sum(n+1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i] = arr[i]+sum[i-1];
	}
	ll ans = 0;
	vector<pair<int,int> > leftborder;
	for(int i=1;i<=n;i++){
		vector<pair<int,int> > temp;
		for(auto e : leftborder){
			int g = __gcd(e.second,arr[i]);
			if(e.first==1 || g!=__gcd(g,arr[e.first-1])) temp.push_back({e.first,g});
		}
		leftborder = temp;
		leftborder.push_back({i,arr[i]});
		for(auto e : leftborder){
			if(i-e.first+1>=k) ans = max(ans,1LL*e.second*(sum[i]-sum[e.first-1]));
		}
	}
	cout<<ans<<"\n";

	return 0;
}
