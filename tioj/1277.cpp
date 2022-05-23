//go through all the possible l and r, use dp for u and d
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    ll sum[n][n+1]={{0}};
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            int a;cin>>a;
            sum[i][j]=sum[i][j-1]+a;
        }
    }
     ll maxn = INT_MIN;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll dp=INT_MIN;
           
            for(int k=0;k<n;k++){
                dp = max(dp,0LL)+sum[k][j]-sum[k][i];
                maxn = max(dp,maxn);
            }
        }
    }

    cout<<max(maxn,0LL)<<endl;




    return 0;
}