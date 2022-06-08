#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    ll dp[n+1][m+1];
    int h[n+1];
    int c[n+1];
    for(int i=1;i<=n;i++){
        cin>>h[i]>>c[i];
    }
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(!i || !j){
                if(j) dp[i][j]=-1e15;
                else dp[i][j]=0;
            } else{
                if(j>=c[i]) dp[i][j] = max(dp[i-1][j],dp[i][j-c[i]]+h[i]);
                else dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][m]<<endl;





    return 0;
}