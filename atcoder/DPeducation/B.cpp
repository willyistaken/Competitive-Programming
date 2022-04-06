#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;int k;cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    fill(dp,dp+n,1e9);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i+j<=n-1){
                if(dp[i+j]>=dp[i]+abs(arr[i]-arr[i+j])){
                    dp[i+j]=dp[i]+abs(arr[i]-arr[i+j]);
                }
            }
        }
    }
    cout<<dp[n-1]<<endl;
}