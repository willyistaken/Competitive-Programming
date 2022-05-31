#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int arr[n][m];
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    dp[0][0]=max(0,arr[0][0]);
    int maxn=dp[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                if(i==0 && j==0) continue;
                if(i==0){
                    dp[i][j]=max(dp[i][j-1],0)+arr[i][j];
                }else{
                    dp[i][j]=max(dp[i-1][j],0)+arr[i][j];
                }
            }else{
                dp[i][j]=max({dp[i-1][j],dp[i][j-1],0})+arr[i][j];
            }
            maxn=max(maxn,dp[i][j]);
        }
    }
    cout<<maxn<<endl;





    return 0;
}