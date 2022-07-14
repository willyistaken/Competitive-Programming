#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[205][205];
int arr[205];

int DP(int l,int r){
	if(l<0 || r>=205 || l>=205 || r<0 || l>r) return INT_MAX;
	if(r-l==0) return 1;
	if(dp[l][r]) return dp[l][r];
	if(arr[l]==arr[r]){
		dp[l][r] = min(DP(l+1,r),DP(l,r-1));
		return dp[l][r];
	}
	int minn = INT_MAX;
	for(int i=l;i<r;i++){
		minn = min(minn,DP(l,i)+DP(i+1,r));
	}
	dp[l][r] = minn;
	return dp[l][r];
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int m;cin>>m;
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++) cin>>arr[i];
		cout<<DP(0,n-1)<<"\n";	
		


	}

	return 0;
}
