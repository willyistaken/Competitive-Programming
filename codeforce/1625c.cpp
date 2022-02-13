#include <bits/stdc++.h>
using namespace std;

int main(){
    int c[505]={0};
    int s[505]={0};
    int dp[505][505]={{0}};
    int lasts[505][505]={{0}};
    int n,l,ka;cin>>n>>l>>ka;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    c[n+1]=l;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int all=0;
    for(int i=1;i<=n;i++){
        all+=(c[i+1]-c[i])*s[i];
    }

    for(int i=1;i<=n;i++){
        dp[i][0]=all;
        lasts[i][0]=s[i];
    }
    for(int i=0;i<=n;i++){
       dp[1][i]=all;
       lasts[1][i]=s[1];
    }
    for(int i=2;i<=n;i++){
        for(int k=1;k<=min(ka,i);k++){
            if(dp[i-1][k]>dp[i-1][k-1]+((lasts[i-1][k-1]-s[i])*(c[i+1]-c[i])) ){
                dp[i][k]=dp[i-1][k-1]+((lasts[i-1][k-1]-s[i])*(c[i+1]-c[i]));
                lasts[i][k]=lasts[i-1][k-1];
            }else{
                dp[i][k]=dp[i-1][k];
                lasts[i][k]=s[i];
            }
        
        }
    }
    int mn=1e9;
    for(int i=0;i<=ka;i++){
        if(dp[n][i]<mn&&dp[n][i]>0){
            mn=dp[n][i];
        }
    }1
    
}