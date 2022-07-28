#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,M;
	cin>>n>>k>>M;	
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	pair<int,int> dp[n+1];
	for(int i=1;i<=n;i++) dp[i] = {INT_MAX,INT_MAX};
	dp[0] = {0,0};
	for(int j=0;j<n;j++){
		if(arr[j]>M) continue;
		for(int i=n;i>=1;i--){
				pair<int,int> prev = dp[i-1];
				prev.second+=arr[j];
				if(prev.second>M){
					prev.first+=1;
					prev.second=arr[j];
				}
				dp[i] = min(dp[i],prev);
		}
	}
	for(int i=n;i>=0;i--){
		if(dp[i].first<k){
			cout<<i<<"\n";
			return 0;
		}
	}
	
	return 0;
}


/*
STUCK:  what is the optimal strategies
THINK: is the smaller the better, could I construct a counter example or proof it
	can't think of counter example: proof?
AHA: greedly chose first A smallest turtle and see if possible:binary search
doesn't work


try dp


It is the dp trick used in LIS , which is dp the answer and search for the biggest answer that match the condition




*/
