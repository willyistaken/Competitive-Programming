#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[105][105];
int DP(int x,int y){
	if(x==y) return 1;
	if(x==1) return y;
	if(y==1) return x;
	if(dp[x][y]) return dp[x][y];
	int minn = INT_MAX;
	for(int i=1;i<=(x/2);i++){
		minn = min(minn,DP(i,y)+DP(x-i,y));
	}
	for(int i=1;i<=(y/2);i++){
		minn = min(minn,DP(x,i)+DP(x,y-i));
	}
	dp[x][y]=minn;
	return dp[x][y];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	cout<<DP(n,m)<<"\n";
	return 0;
}
