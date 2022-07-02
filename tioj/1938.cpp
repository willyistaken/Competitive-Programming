#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n,a,b,c,d;cin>>m>>n>>a>>b>>c>>d;
	ll dp[m][m];
	for(int i=0;i<n;i++){
		for(int x = m-1;x>=0;x--){
			for(int y=m-1;y>=0;y--){
				dp[x][y] = (! ((y && x) || i==0) ) ? LONG_LONG_MIN:((i) ? dp[x-1][y-1]+(a*i+b*x+c*y)%d : (a*i+b*x+c*y)%d);
			}
		}
		for(int x = 0;x<m;x++){
			for(int y=0;y<m;y++){
				dp[x][y] = max({dp[max(0,x-1)][y],dp[x][max(0,y-1)],dp[x][y]});
			}
		}
	}

	cout<<dp[m-1][m-1]<<"\n";
	return 0;
}


//dp transfer dp[x][y][i] = (0<=n<x 0<=m<y)max(dp[n][m][i-1])+(ai+bx+cy)%d
//plus rolling and simple optimization
