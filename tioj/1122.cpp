#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
    ll sum[n+1][n]={{0}};
    cin>>sum[1][0];
    for(int j=0;j<n;j++){
        for(int i=0;i<=n;i++){
            if(i==0){
                sum[i][j]=0;
            }
            if(i==1){
               if(j!=0){
                   sum[i][j]=sum[1][0]+j+1;
               } 
            }
            if(i>1){
                sum[i][j]=sum[i-1][j] +   (((sum[i-1][j]-sum[i-2][j])*17)%103)*(((i+j)%2) ? 1:-1);
            }
        }
    }
    ll maxn = LONG_LONG_MIN;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll now=sum[j][0]-sum[i][0];
            maxn = max(now,maxn);
            for(int k=1;k<n;k++){
                now = max(0LL,now)+sum[j][k]-sum[i][k];
                maxn = max(maxn,now);
            }
        }
    }
    cout<<maxn<<endl;
    }



    return 0;
}