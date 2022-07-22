#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct p{
	ll v;
	int d;
	int oj;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	ll v[m+1]={0};
	for(int i=1;i<=m;i++) cin>>v[i];
	p arr[n];
	for(int i=0;i<n;i++) cin>>arr[i].v>>arr[i].d>>arr[i].oj;
	sort(arr,arr+n,[](const p &a,const p &b){return a.d<b.d;});
	ll dp[n]={0};
	ll ans=max(0LL,arr[0].v);
	dp[0] = arr[0].v;
	for(int i=1;i<n;i++){
		ll maxn = 0;	
		for(int j=i-1;j>=0;j--){
			maxn = max(maxn,dp[j] - ((arr[i].oj==arr[j].oj)*v[arr[i].oj]));
		}
		dp[i] = maxn+arr[i].v;
		ans = max(ans,dp[i]);
	}
	cout<<ans<<"\n";
	
	return 0;
}
