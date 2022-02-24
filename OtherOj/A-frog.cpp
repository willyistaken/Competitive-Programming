#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    fill(dp,dp+n,1e9);
    dp[0]=0;
    for(int i=0;i<n-1;i++){
        if(dp[i+1]>=dp[i]+abs(arr[i]-arr[i+1])){
            dp[i+1]=dp[i]+abs(arr[i]-arr[i+1]);
        }
        if(i!=n-2){
            if(dp[i+2]>=dp[i]+abs(arr[i]-arr[i+2])){
            dp[i+2]=dp[i]+abs(arr[i]-arr[i+2]);
        }
        }
    }
    cout<<dp[n-1]<<endl;
}