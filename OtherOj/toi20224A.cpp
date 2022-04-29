#include <bits/stdc++.h>
using namespace std;


int h,w;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool inbound(int x,int y){
    if(x<h && x>=0){
        if(y<w && y>=0){
            return true;
        }
    }
    return false;
}
void dfs(int sx,int sy,short color,vector<vector<short>> &arr,short target){
    arr[sx][sy]=target;
    for(int i=0;i<4;i++){
        if(inbound(sx+dx[i],sy+dy[i])){
           if(arr[sx+dx[i]][sy+dy[i]]==color){
               dfs(sx+dx[i],sy+dy[i],color,arr,target);
           } 
        }
    }
}

int main(){
    cin>>h>>w;
    int sx,sy;cin>>sx>>sy;
    vector<vector<short>> arr(h,vector<short>(w,0));
    short z;cin>>z;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }
    short color = arr[sx-1][sy-1];
    dfs(sx-1,sy-1,color,arr,z);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<arr[i][j]<<" \n"[j==w-1];
        }
    }
}