#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){



    int n,m;cin>>n>>m;
    int w[n+1],v[n+1];
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    int dp[n][10050];
    int maxn=INT_MIN;
    for(int i=0;i<=n;i++){
        for(int j=0;j<10050;j++){
            if(i==0 && j>0) {
                dp[i%2][j]=1e9;
                continue;
            }
            if(i==0 && j==0){
                dp[i%2][j]=0;
                maxn=max(maxn,j);
                continue;
            }
            if(j>=v[i] ) dp[i%2][j]=min(dp[(i+1)%2][j],dp[(i+1)%2][j-v[i]]+w[i]);
            if(j<v[i]) dp[i%2][j]=dp[(i+1)%2][j];
            if(dp[i%2][j]<=m && dp[i%2][j]>=0) maxn=max(maxn,j);
        }
    }
    cout<<maxn<<endl;

    }






    return 0;
}