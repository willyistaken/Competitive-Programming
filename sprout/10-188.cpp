#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){

    int n,k,c;cin>>n>>k>>c;
    ll dp[n]={0};
    deque<int> mono;
    int val[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    dp[0]=val[0];
    mono.push_back(0);
    ll maxn=dp[0];
    for(int i=1;i<n;i++){
        while(mono.front()<i-k) mono.pop_front();
        dp[i]=max(1LL*val[i],dp[mono.front()]-(1LL*c*(i-mono.front()))+val[i]);
        while(!mono.empty()){
           if(dp[mono.back()]+c*mono.back()>dp[i]+c*i) break;
           mono.pop_back();  
        }
        mono.push_back(i);
        maxn=max(maxn,dp[i]);
    }
    cout<<max(maxn,0LL)<<endl;
    }
    return 0;
}