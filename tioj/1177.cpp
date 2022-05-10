#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
struct cor{
    int x;
    int y;
    int t;
};
inline bool inbound(int x,int y,int m){
    return (x>=0 && x<m && y>=0 && y<m);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;cin>>m;
    int n;cin>>n;
    bool arr[m][m]={{0}};
    while(n--){
        int x,y;cin>>x>>y;
        arr[--x][--y]=1;
    }
    int sx,sy;cin>>sx>>sy;
    int ex,ey;cin>>ex>>ey;
    sx--,sy--,ex--,ey--;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    arr[sx][sy]=1;
    queue<cor> bfs;
    bfs.push({sx,sy,0});
    while(!bfs.empty()){
        cor temp = bfs.front();
        bfs.pop();
        if(temp.x==ex && temp.y==ey){
            cout<<temp.t<<endl;
            return 0;
        }
        for(int i=0;i<4;i++){
            if(inbound(temp.x+dx[i],temp.y+dy[i],m)){
                    if(arr[temp.x+dx[i]][temp.y+dy[i]]==0){
                        arr[temp.x+dx[i]][temp.y+dy[i]]=1;
                        bfs.push({temp.x+dx[i],temp.y+dy[i],temp.t+1});
                    }
                }
            }
        }
        cout<<-1<<endl;
        return 0;
    }


