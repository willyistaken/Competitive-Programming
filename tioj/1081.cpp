#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};
bool inbound(int x,int y){
    if(x<n&&x>=0){
        if(y<m&&y>=0){
            return true;
        }
    }
    return false;
}
void dfs(int x,int y,vector<vector<bool>> &arr){
    arr[x][y]=0;
    for(int i=0;i<8;i++){
        if(inbound(x+dx[i],y+dy[i])){
            if(arr[x+dx[i]][y+dy[i]]){
                dfs(x+dx[i],y+dy[i],arr);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while(cin>>n>>m && n && m){

    vector<vector<bool> > arr(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        string k;cin>>k;
        for(int j=0;j<m;j++){
        arr[i][j]=(k[j]=='1');
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]){
                ++ans;
                dfs(i,j,arr);
            }
        }
    }
    cout<<ans<<"\n";
    }
}
