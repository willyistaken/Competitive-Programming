#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	map<ll,int> s;
	for(int i=0;i<n;i++){
		ll x,y;int w;cin>>x>>y>>w;
		s[(x*x)+(y*y)]+=w;
	}
	vector<int> arr;
	for(auto i : s){
		arr.push_back(i.second);
	}
	ll ans=0;
	ll cur=0;
	for(auto i : arr){
		cur = max(cur+i,(ll)i);
		ans = max(cur,ans);
	}
	cout<<ans<<"\n";
	return 0;
}
