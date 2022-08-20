#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n && n){
		int l[n+1],r[n+1],p[n+1];
		int dp[n+1][n+1]={{0}};
		for(int i=1;i<=n;i++) cin>>l[i]>>r[i]>>p[i];
		for(int i=1;i<=n;i++){
			l[i]--;
			for(int j=1;j<=n;j++){
				if(j>i) dp[i][j] = 1e9;
				else{
					if(i==1) dp[i][j] = (l[1]+p[1]<=r[1])?(l[1]+p[1]):(1e9);
					else{
						dp[i][j] = dp[i-1][j];
						if(max(dp[i-1][j-1],l[i])+p[i]<=r[i]) dp[i][j] = min(dp[i][j],max(dp[i-1][j-1],l[i])+p[i]);
					}
				}
				//cout<<dp[i][j]<<" ";
			}
			//cout<<"\n";
		}
		int ans=0;
		for(int i=0;i<=n;i++) if(dp[n][i]<=r[n]) ans = i;
		cout<<ans<<"\n";
	}

	return 0;
}

// try dp other stuff
