#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m){
    int sum[m+1][n] = {{0}};
    for(int k=0;k<n;k++){
        for(int i=0;i<=m;i++){
            if(!i){
                 sum[i][k]=0;
                 continue;
            }
            cin>>sum[i][k];
            sum[i][k]+=sum[i-1][k];
        }
    }
    int maxn = INT_MIN;
    for(int i=0;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            int now=sum[j][0]-sum[i][0];
            maxn=max(now,maxn);
            for(int g=1;g<n;g++){
               now = max(now+sum[j][g]-sum[i][g],sum[j][g]-sum[i][g]);
               maxn = max(maxn,now);
            }
        }
    }
    cout<<maxn<<endl;
    }



    return 0;
}