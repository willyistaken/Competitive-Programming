#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){

    int n;cin>>n;
    long long d[n+1];
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    d[0]=0;
    long long dp[n+1];
    dp[0]=0;
    dp[1]=0;//why?
    dp[2]=abs(d[2]-d[1]);
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[(i-1)]+abs(1LL*d[i]-d[i-1]),dp[(i-2)]+abs(1LL*d[i]-d[i-2]));
    }
    cout<<dp[n]<<endl;
    }


}