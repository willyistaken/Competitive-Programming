#include <bits/stdc++.h>
using namespace std;
int n,m;
bool inbound(int x,int y){
    if(x<m && x>=0){
        if(y<n && y>=0){
            return true;
        }
    }
    return false;
}
struct st{
    int x;
    int y;
    int t;
};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
    int t;cin>>t;
    while(t--){

    cin>>m>>n;
    vector<vector<int> > maps(m,vector<int>(n,0));
    vector<vector<bool> > done(m,vector<bool>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maps[i][j];
        }
    }
    queue<st > bfs;
    bfs.push(st{0,0,0});
    done[0][0]=0;
    while(!bfs.empty()){
       st cur= bfs.front();
       bfs.pop();
       if(done[cur.x][cur.y]==0){
         done[cur.x][cur.y]=true;
        if(cur.x==m-1 && cur.y==n-1){
            cout<<cur.t<<endl;
            break;
        }
        for(int i=0;i<4;i++){
            if(inbound(cur.x+dx[i],cur.y+dy[i])){
                if(abs(maps[cur.x][cur.y]-maps[cur.x+dx[i]][cur.y+dy[i]])<=5){
                    if(done[cur.x+dx[i]][cur.y+dy[i]]==0){
                        bfs.push(st{cur.x+dx[i],cur.y+dy[i],cur.t+1});
                    }
                }
            }
        }   
       }
      

    }
    }




}