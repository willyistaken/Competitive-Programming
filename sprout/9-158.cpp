#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n,m,k;cin>>n>>m>>k;
    int w[n+1],v[n+1];
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    int dp[2][m+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int h=0;h<=k;h++){
                if(i==0 || j==0 || h==0){
                    dp[i%2][j][h]=0;
                    continue;
                }
                if(j>=w[i] && h>=1) {
                    dp[i%2][j][h]=max(dp[(i+1)%2][j][h],dp[(i+1)%2][j-w[i]][h-1]+v[i]);
                }else{
                    dp[i%2][j][h]=dp[(i+1)%2][j][h];
                }
            }
        }
    }
    cout<<dp[n%2][m][k]<<endl;
    }    




    return 0;
}


/*
2
3 6 3
2 4
3 5
4 6
3 9 2
2 4
3 5
4 6
*/