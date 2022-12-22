#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



ll dp[5005][5005];
int arr[5005];
ll sum[5005];

ll DP(int l,int r){
	if(l==r) return arr[l];
	if(dp[l][r]) return dp[l][r];
	dp[l][r] = sum[r-1]-sum[l-1]-DP(l,r-1)+arr[r];
	dp[l][r] = max(dp[l][r],sum[r]-sum[l]-DP(l+1,r)+arr[l]);
	return dp[l][r];
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	sum[0]=0;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		sum[i]=arr[i]+sum[i-1];
	}
	cout<<DP(1,n)<<"\n";	
	return 0;
}