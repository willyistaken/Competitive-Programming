#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;int m;
    while(cin>>n>>m && n && m){
    int dis[n][n];
    fill_n(dis[0],n*n,(int)1e9);
    
    while(m--){
        int a,b;cin>>a>>b;
        dis[a-1][b-1]=1;
    }
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            } 
        }
    }
    int minn=INT_MAX;
    for(int i=0;i<n;i++){
        minn=min(minn,dis[i][i]);
    }
    cout<<((minn==(int)1e9) ? 0:minn)<<endl;
    }
    return 0;
}