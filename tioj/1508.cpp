//01 knapsack
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;cin>>m;
    int n;cin>>n;
    while(m--){
    int sum=0;
    int arr[n+1];
    for(int i = 0;i<n;i++){
        cin>>arr[i+1];
        sum+=arr[i+1];
    }
    if(sum%2){
        cout<<"No\n";
        continue;
    }
    bool dp[n+1][(sum/2)+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=(sum/2);j++){
            if(j==0){
                dp[i][j]=1;
                continue;
            }
            if(i==0){
                dp[i][j]=0;
                continue;
            }
            if(j>=arr[i]){
                dp[i][j]=(dp[i-1][j-arr[i]] || dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }    
        }
    }
    if(dp[n][(sum/2)]){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }


    }
    return 0;
}