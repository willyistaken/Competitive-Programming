#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    ll sum[n+1];
    sum[0]=0;
    for(int i=1;i<=n;i++){
        ll a;
        scanf("%lld",&a);
        sum[i]=sum[i-1]+a;
    } 

    vector<vector<ll> > dp(n+1,vector<ll>(2,(ll)-1e16));
    dp[0][0]=0;
    ll ans = (ll)-1e16;
    for(int m=1;m<=n;m++){
        if(m>=2) dp[0][(m+1)%2]=(ll)-1e16;
     for(int i=1;i<=n;i++){
         
        ll maxn =(ll)-1e16;
        for(int j=i-1;j>=max(0,i-k);j--){
            maxn =  max(maxn,dp[j][(m+1)%2]+((m-1)*(sum[i]-sum[j])));
        }
            dp[i][m%2]=maxn;
            if(i==n){
                ans = max(ans,maxn);
            }
    }
}
printf("%lld\n",ans);
return 0;
}