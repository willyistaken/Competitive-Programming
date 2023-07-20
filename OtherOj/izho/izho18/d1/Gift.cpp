#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll



signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	ll sum=0;
	vector<int> arr(n);
	priority_queue<pair<int,int> > pq;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		pq.push({arr[i],i});
	}
	if(sum%k){
		cout<<-1<<"\n";
		return 0;
	}
	if(pq.top().first>sum/k){
		cout<<-1<<"\n";
		return 0;
	}
	vector<vector<int>> ans;
	while(sum){
		vector<int> v;
		ll tomi = LONG_LONG_MAX;
		for(int i=0;i<k;i++){
			v.push_back(pq.top().second);
			tomi = pq.top().first;
			pq.pop();
		}
		if(pq.size()) tomi = min(tomi,(sum/k)-pq.top().first);
		sum-=k*tomi;
		vector<int> tempans;
		tempans.push_back(tomi);
		for(auto i : v){
			tempans.push_back(i+1);	
			arr[i]-=tomi;
			if(arr[i]) pq.push({arr[i],i});
		}
		ans.push_back(tempans);
	}
	cout<<ans.size()<<"\n";
	for(auto ar : ans){
		for(auto v : ar){
			cout<<v<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
