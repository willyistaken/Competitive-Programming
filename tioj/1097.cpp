#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int l,w;
	while(cin>>l>>w &&(l||w)){
		int dp[w+1][2]={{0}};
		int ans=0;
		for(int j=0;j<l;j++){
			for(int i=1;i<=w;i++){
				int k;cin>>k;
				if(k>1){
					dp[i][j%2]=0;	
				}else{
					dp[i][j%2] = min({dp[i-1][j%2],dp[i-1][(j+1)%2],dp[i][(j+1)%2]}) +1;
				}
				ans = max(ans,dp[i][j%2]);
			}
		}
		cout<<ans*ans<<endl;
	}

	return 0;
}

