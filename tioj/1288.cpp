#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[100][2];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int maxn=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            int now;cin>>now;
            if(j-1>=0){
                dp[j][i%2]=max(dp[j][i%2],dp[j-1][(i+1)%2]);
            }
            dp[j][i%2]=max(dp[j][i%2],dp[j][(i+1)%2]);
            dp[j][i%2]+=now;
            maxn = max(dp[j][i%2],maxn);
        }
    }
    cout<<maxn<<endl;






    return 0;
}
