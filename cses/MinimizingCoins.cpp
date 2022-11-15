#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x;cin>>n>>x;
	ll dp[x+1];
	fill(dp,dp+x+1,1e9);
	dp[0] = 0;
	for(int i =0;i<n;i++){
		int a;cin>>a;
		for(int v = a;v<=x;v++){
			dp[v] = min(dp[v-a]+1,dp[v]);	
		}
	}
	if(dp[x]>=1e9) cout<<-1<<"\n";
	else cout<<dp[x]<<"\n";
	return 0;
}
