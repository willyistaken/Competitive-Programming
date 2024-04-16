#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


const int N = 2050;

int cost[N][N];
ll dp[2][N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>cost[i][j];
	}
	for(int i=1;i<n;i++){
		int b = (i&-i);
		for(int x=0;x<=n;x++) dp[i&1][x]=1e18;
		for(int x=0;x<n;x++){
			int l = x^b;
			l&=(~(b-1));
			for(int j=l;j<l+b;j++) dp[i&1][x] = min(dp[i&1][x],dp[!(i&1)][j]+cost[x][j]);
		}
	}
	ll minn = 1e18;
	for(int i=0;i<n;i++) minn = min(minn,dp[(n-1)&1][i]);
	cout<<minn<<"\n";

	return 0;
}
