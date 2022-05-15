#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[16][1<<16];
int n;
int dis[16][16];
int solve(int x,int s){
    if(dp[x][s]+1) return dp[x][s];
    int minn=INT_MAX;
    for(int i=0;i<n;i++){
        if(i!=x && (s>>i)&1){
            minn = min(solve(i,s-(1<<x))+dis[x][i],minn);
        }
    }
    dp[x][s]=minn;
    return dp[x][s];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        continue;
    }
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            dis[i][j]=0;
        }
        for(int j=0;j<1<<16;j++){
            dp[i][j]=-1;//this//
        }
    }    
    for(int i=0;i<n-1;i++){
        dis[i][i]=0;
        for(int j=i+1;j<n;j++){
            cin>>dis[i][j];
            dis[j][i]=dis[i][j];
        }
    }
    for(int i=1;i<n;i++){
        dp[i][1<<i]=dis[0][i];

    }
    int minn=INT_MAX;
    for(int i=1;i<n;i++){
        minn=min(minn,(solve(i,(1<<n)-2)+dis[0][i]));
    }
    cout<<minn<<endl;
    }



    return 0;
}