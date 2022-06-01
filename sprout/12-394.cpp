#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int dis[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dis[i][j];
            if(dis[i][j]<0) dis[i][j]=1e5;
        }
    }
    for(int t=0;t<n;t++){
            int maxn=0;
            for(int cheat=0;cheat<1;cheat++){     
            for(int i=0;i<=t;i++){
                for(int j=0;j<=t;j++){
                    dis[i][t]=min(dis[i][t],dis[i][j]+dis[j][t]);
                    dis[t][i]=min(dis[t][i],dis[t][j]+dis[j][i]);
                }
            }    
            for(int i=0;i<=t;i++){
                for(int j=0;j<=t;j++){
                    dis[i][j]=min(dis[i][j],dis[i][t]+dis[t][j]);
                }
            }
        
       
            }
            for(int i=0;i<=t;i++){
                for(int j=0;j<=t;j++){
                    maxn=max(maxn,dis[i][j]);
                }
            }
            cout<<((maxn>=1e4) ? -1:maxn)<<" \n"[t==n-1];
     }
    





    return 0;
}