#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int dp[505][505];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b;cin>>a>>b;	
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(i==j) dp[i][j] = 0;
			else if(i==1 || j ==1) dp[i][j] = max(i,j)-1;
			else{
				int minn = 1e9+5;
				for(int c=1;c<i;c++) minn = min(minn,dp[c][j]+dp[i-c][j]);
				for(int c=1;c<j;c++) minn = min(minn,dp[i][c]+dp[i][j-c]);
				dp[i][j] = minn+1;
			}
		}
	}
	cout<<dp[a][b]<<"\n";

	return 0;
}
