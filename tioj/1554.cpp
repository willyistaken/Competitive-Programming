#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[(1<<20)];
int p[20][20];
int n;
    
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>p[i][j];
        }
    }
    int top = 1<<n; 
    double ans=0;
    for(int k=0;k<n;k++){
        for(int mask=0;mask<top;mask++ ){
            if(__builtin_popcount(mask)>n-k) continue;
            double maxn=0;
            if(k==0){
                for(int i=0;i<20;i++){
                    if((mask>>i)&1) continue;
                    maxn = max(maxn,(double)p[k][i]/100);
                }
            }else{
                for(int i=0;i<20;i++){
                    if(!((mask>>i)&1)){
                        maxn = max(((double)p[k][i]/100)*dp[mask+(1<<i)],maxn);
                    }
                }
            }
            dp[mask]=maxn;
            if(k==n-1) ans = max(ans,dp[mask]);
        }
    }
    cout<<fixed<<setprecision(2)<<ans*100<<"\n";
    return 0;
}