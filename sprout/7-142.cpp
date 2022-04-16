#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
      int n;cin>>n;
      int k;cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n][2];
    dp[0][0]=0;
    dp[0][1]=arr[0];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        if(i-k>=0){
         dp[i][1]=max(dp[i-k][0],dp[i-k][1])+arr[i];   
        }else{
            dp[i][1]=arr[i];
        }
        
    }
    cout<<max(dp[n-1][1],dp[n-1][0])<<endl;  
    }
    
}