 //偽●單調陣列優化
 #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string arr[2]={"No\n","Yes\n"};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){ 
    int n,m;
    cin>>n>>m;
    bool dp[n+1][m+1];
    int c[n+1];int q[n+1];
     for(int i=1;i<=n;i++){
            cin>>c[i]>>q[i];
        }
        fill(dp[0],dp[0]+m+1,0);
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
           int reminder[c[i]];
           fill(reminder,reminder+c[i],-1);
            for(int j=0;j<=m;j++){
                if(dp[i-1][j]==1){
                    dp[i][j]=1;
                    reminder[j%c[i]]=j;
                }else{
                    if(reminder[j%c[i]]<0 || reminder[j%c[i]]<j-c[i]*q[i]){
                        dp[i][j]=0;
                    }else{
                        dp[i][j]=1;
                    }
                }
            }
        }
        cout<<arr[dp[n][m]];
    }
    return 0;
}
