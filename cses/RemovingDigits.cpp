#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int dp[n+1]={0};
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		int v = i;
		int minn = 1e9;
		while(v){
			if(v%10!=0) minn = min(minn,dp[i-(v%10)]);
			v/=10;
		}
		dp[i] = minn+1;
	}
	cout<<dp[n]<<"\n";


	return 0;
}
