#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    //cout<<n<<" "<<m<<endl;
    int quantity[105];
    for(int i=0;i<n;i++){
        cin>>quantity[i+1];
    }
    int dp[n+5][m+5]={{0}};
    for(int i=1;i<=m;i++){
        dp[1][i]=1;
    }
    for(int j=2;j<=n;j++){
        for(int g=m;g>=0;g--){      
            for(int k=1;k<=quantity[j];k++){
            if(g-k>=0){
                dp[j][g]+=(dp[j-1][g-k]);
            dp[j][m]=dp[j][m]%1000007;
            }
        }
        }
  
    }
    cout<<dp[n][m]<<endl;
}
