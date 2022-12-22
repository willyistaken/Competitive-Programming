#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;

ll dis(pair<ll,ll> p1,pair<ll,ll> p2){
	ll dx = p1.first-p2.first;
	ll dy = p1.second-p2.second;
	return dx*dx+dy*dy;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	pair<ll,ll> arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+n);
	int j = 0;
	ll dd = dis(arr[0],arr[1]);
	set<pair<ll,ll> > s;
	s.insert({arr[0].second,arr[0].first});
	s.insert({arr[1].second,arr[1].first});
	for(int i=2;i<n;i++){
		ll d = ceil(sqrt(dd));
		while(arr[i].first-arr[j].first>=d && j<i){
			s.erase({arr[j].second,arr[j].first});
			j+=1;
		}
		auto lit = s.lower_bound({arr[i].second-d,0});
		auto uit = s.upper_bound({arr[i].second+d,0});
		for(auto it = lit;it!=uit;++it){
			dd = min(dd,dis(arr[i],{it->second,it->first}));
		}
		s.insert({arr[i].second,arr[i].first});
	}

	cout<<dd<<"\n";

	return 0;
}
