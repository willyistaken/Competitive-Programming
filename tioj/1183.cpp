#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int sx,sy,ex,ey;
bool arr[20][20];
bool vis[20][20];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char dir[4] = {'U','D','R','L'};
bool inbound(int x,int y){
    return (0<=x && x<n && 0<=y && y<m);
}
void dfs(int x,int y){
    if(x==ex && y==ey) return ;
    vis[x][y]=1;

    for(int i=0;i<4;i++){
        if(inbound(x+dx[i],y+dy[i]) && !vis[x+dx[i]][y+dy[i]] && arr[x+dx[i]][y+dy[i]] ){
            cout<<dir[i];
            dfs(x+dx[i],y+dy[i]);
            break;    
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis)); 
        sx=sy=ex=ey=0;
        for(int i=0;i<n;i++){
            string s;cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='#') arr[i][j]=0;
                else arr[i][j]=1;

                if(s[j]=='S'){
                    sx=i;sy=j;
                }
                if(s[j]=='T'){
                    ex=i;ey=j;
                }
            }
        }
        dfs(sx,sy);
        cout<<"\n";

    }







    return 0;
}