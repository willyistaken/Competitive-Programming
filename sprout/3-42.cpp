#include <bits/stdc++.h>
using namespace std;
void dfs(int x,int y,vector<vector<bool> > &arr){
    if(arr[x][y]){
        arr[x][y]=0;
        dfs(x+1,y,arr);
        dfs(x-1,y,arr);
        dfs(x,y+1,arr);
        dfs(x,y-1,arr);
    }
    
    
}
int main(){
    int t;cin>>t;
    while(t--){
        int w,h;cin>>w>>h;
    vector<vector<bool> > arr(w+2,vector<bool>(h+2,0));
    for(int i=1;i<=w;i++){
        string c;cin>>c;
        for(int j=0;j<h;j++){
            if(c[j]=='.') arr[i][j+1]=1;
        }
    }
    int count=0;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(arr[i][j]){
                dfs(i,j,arr);
                count++;
            }
        }
    }
    cout<<count<<endl;
    }
    
}