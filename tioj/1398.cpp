#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		priority_queue<ll,vector<ll>,greater<ll>> pq;
		if(n==1){
			int k;cin>>k;
			cout<<k<<"\n";
			continue;
		}
		if(n%2==0) pq.push(0);
		for(int i=0;i<n;i++){
			int k;cin>>k;
			pq.push(k);
		}
		ll ans=0;
		while(pq.size()>1){
			ll now = 0;
			now+=pq.top();
			pq.pop();
			now+=pq.top();
			pq.pop();
			now+=pq.top();
			pq.pop();
			ans+=now;
			pq.push(now);
		}
	
		cout<<ans<<"\n";
	}

	return 0;
}
// greedy
