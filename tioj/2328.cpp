#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2005;
ll dp[N];
ll arr[N];

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,p;cin>>n>>k>>p;
	if(n>2000){
		cout<<"pccorz\n";
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>arr[i];
	priority_queue<int> pq;
	for(int i=1;i<=n;i++){
		dp[i]=-1e18;
		while(!pq.empty()){
			pq.pop();
		}
		ll sum = 0;
		for(int j=i-1;j>=0;j--){
			sum+=arr[j+1];
			pq.push(arr[j+1]);
			while(pq.size()>k && !pq.empty()) {
				sum-=pq.top();
				pq.pop();
			}
			dp[i] = max(sum+dp[j],dp[i]);
		}
		dp[i]-=p;
	}
	cout<<dp[n]<<"\n";
	return 0;
}
