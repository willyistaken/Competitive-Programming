#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){

    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool dp[n][10]={{0}};
    dp[0][0]= 1;dp[0][1]=1;dp[0][2]=1;
    for(int i=1;i<n;i++){
        bool no=0;
        switch(arr[i]-arr[i-1]){
          case 1:
            dp[i][0] = dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            break;
          case 2:
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][2];
            dp[i][2] = 0;
            break;
          case 3:
            dp[i][0] = dp[i-1][2];
            dp[i][1]=0;
            dp[i][2]=0;
            break;
          default:
            no=1;
            break;
             
        }
        if(no) break;
       
    }
    cout<<vector<string>{"No\n","Yes\n"}[dp[n-1][0] || dp[n-1][1] || dp[n-1][2]];    
    }

}