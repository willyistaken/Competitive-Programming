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

    vector<ll> dp(n+1,(ll)-1e16);
    dp[n]=0;
    deque<int> mono;
    mono.push_back(n);
    for(int i=n-1;i>=1;i--){
        while(!mono.empty()&& mono.front()>i+k) mono.pop_front();
        dp[i]=dp[mono.front()]+sum[n]-sum[mono.front()-1];
        if(i+k>n) dp[i] = max(0LL,dp[i]);
        while(!mono.empty()){
            if(dp[mono.back()]-sum[mono.back()-1]>dp[i]-sum[i-1]) break;
            mono.pop_back();
        }
        mono.push_back(i);
    }
    printf("%lld\n",dp[1]);

    return 0;
}