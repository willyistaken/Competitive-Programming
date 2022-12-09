#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct project{
	int l,r,p;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	vector<int> rs;
	project arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].l>>arr[i].r>>arr[i].p;
		rs.push_back(arr[i].r);
	}
	sort(arr,arr+n,[](const project &a,const project &b){return a.r<b.r;});
	sort(rs.begin(),rs.end());
	ll dp[n] = {0};
	dp[0] = arr[0].p;
	
	for(int i=1;i<n;i++){
		int llim = lower_bound(rs.begin(),rs.end(),arr[i].l)-rs.begin();
		if(llim==0) dp[i] = max(1LL*arr[i].p,dp[i-1]);
		else dp[i] = max(dp[i-1],dp[llim-1]+arr[i].p);
	}
	cout<<dp[n-1]<<"\n";
	return 0;
}
