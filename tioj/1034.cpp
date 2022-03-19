#include <bits/stdc++.h>
using namespace std;
int n;
int flatten(int x,int y){
    if( 0<=n*(y-1)+x-1 && n*n>=n*(y-1)+x){
        return n*(y-1)+x-1;
    }else{
        return -1;
    }

}
int main(){
    cin>>n;
    int shortest[n*n][n*n];
    int maxn[n*n][n*n];
    for(int i=0;i<n*n;i++){
        for(int j=0;j<n*n;j++){
            shortest[i][j]=1e9;
        }
    }
    fill_n(&maxn[0][0],n*n,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>shortest[flatten(i,j)][flatten(i,j)];
            //cout<<shortest[flatten(i,j)][flatten(i,j)];
            maxn[flatten(i, j)][flatten(i, j)]=shortest[flatten(i,j)][flatten(i,j)];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(flatten(i-1,j)+1){
                shortest[flatten(i,j)][flatten(i-1,j)]=shortest[flatten(i,j)][flatten(i,j)]+shortest[flatten(i-1,j)][flatten(i-1,j)];
                maxn[flatten(i,j)][flatten(i-1,j)]=max(maxn[flatten(i,j)][flatten(i,j)],maxn[flatten(i-1,j)][flatten(i-1,j)]);
            }
            if(flatten(i+1,j)+1){
                shortest[flatten(i,j)][flatten(i+1,j)]=shortest[flatten(i,j)][flatten(i,j)]+shortest[flatten(i+1,j)][flatten(i+1,j)];
                maxn[flatten(i,j)][flatten(i+1,j)]=max(maxn[flatten(i,j)][flatten(i,j)],maxn[flatten(i+1,j)][flatten(i+1,j)]);
            }
            if(flatten(i,j-1)+1){
                shortest[flatten(i,j)][flatten(i,j-1)]=shortest[flatten(i,j)][flatten(i,j)]+shortest[flatten(i,j-1)][flatten(i,j-1)];
                maxn[flatten(i,j)][flatten(i,j-1)]=max(maxn[flatten(i,j)][flatten(i,j)],maxn[flatten(i,j-1)][flatten(i,j-1)]);
            }
            if(flatten(i,j+1)+1){
                shortest[flatten(i,j)][flatten(i,j+1)]=shortest[flatten(i,j)][flatten(i,j)]+shortest[flatten(i,j+1)][flatten(i,j+1)];
                maxn[flatten(i,j)][flatten(i,j+1)]=max(maxn[flatten(i,j)][flatten(i,j)],maxn[flatten(i,j+1)][flatten(i,j+1)]);
            }
    }
    }
    for(int i=0;i<n*n;i++){
        for(int j=0;j<n*n;j++){
            cout<<shortest[i][j]<<",";
        }
        cout<<endl;
    }
    for(int i=0;i<n*n;i++){
        for(int j=0;j<n*n;j++){
            for(int k=0;k<n*n;k++){
                if(shortest[i][j]>shortest[i][k]+shortest[k][j]  ){
                    shortest[i][j]=shortest[i][k]+shortest[k][j];
                    maxn[i][j]=max(maxn[i][k],maxn[k][j]);
                }
            }
        }
    }
    
    int q;cin>>q;
    while(q--){
        int fromx,fromy,tox,toy;cin>>fromx>>fromy>>tox>>toy;
        cout<<shortest[flatten(fromx,fromy)][flatten(tox,toy)]<<endl;
    }
    
}