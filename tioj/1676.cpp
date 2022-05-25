#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    ll dp[n+1]={0};ll sum[n+1]={0};
    ll a[n+1]={0}; ll b[n+1]={0};
    ll temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+temp[n-i];
    }
    deque<int> mono;
    dp[1]=-1;
    a[1]=2LL*1;
    b[1]=dp[1]+sum[1]-1;
    mono.emplace_back(1);
    for(int i=2;i<=n;i++){
        while(mono.size()>=2 && mono.front()<i-k) mono.pop_front();
        while(mono.size()>=2){
            if(a[mono[0]]*i+b[mono[0]]>a[mono[1]]*i+b[mono[1]]){
                break;
            }
            mono.pop_front();
        }   
        dp[i]=a[mono.front()]*i+b[mono.front()]-(1LL*i*i);
        dp[i] = (i-k<=0) ? max(dp[i],(-1LL*i*i)) : dp[i];
        a[i]=2LL*i;
        b[i]=dp[i]+sum[i]-(1LL*i*i);
        while(mono.size()>=2){
            int o = mono.size()-1;//
            if((b[mono[o]]-b[i])*(a[mono[o]]-a[mono[o-1]])>(b[mono[o-1]]-b[mono[o]])*(a[i]-a[mono[o]]) || (mono[o-1]+k)*(a[i]-a[mono[o]])<(b[mono[o]]-b[i])){//the part before || means that we need to make sure that convexity always hold.  the part after || means that we need to make sure that the point we are poping will never be the best line, to make sure of that we use the slope where the point expire to test it, if it is better than we don't pop that;
                break;
            }
            mono.pop_back();
        }
        mono.push_back(i);
    
    }
    cout<<dp[n]<<endl;

    return 0;
}