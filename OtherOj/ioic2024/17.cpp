#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


ll dp[87];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<87;i++){
		dp[i]  = dp[i-1]+dp[i-2];
	}
	cout<<dp[n]<<"\n";

	return 0;
}
