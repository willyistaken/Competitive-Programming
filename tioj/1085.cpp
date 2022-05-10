#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
struct cor{
    int x;
    int y;
    int z;
};
int n,m,g;
inline bool inbound(int x,int y,int z){
    return (x>0 && x<=n && y>0 && y<=m && z>0 && z<=g);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>g;
    int arr[n+1][m+1][g+1];
    for(int i=1;i<=g;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                cin>>arr[k][j][i];
            }
        }
    }
    int dx[6]={0,0,0,0,1,-1} ;
    int dy[6]={0,0,1,-1,0,0} ;
    int dz[6]={1,-1,0,0,0,0} ;
    queue<cor> bfs;
    if(arr[1][1][1]){
        cout<<"no route\n";
        return 0;
    }else{
        arr[1][1][1]=1;
    }
    bfs.push({1,1,1});
    while(!bfs.empty()){
        cor temp = bfs.front();
        bfs.pop();
        if(temp.x==n && temp.y==m && temp.z==g){
            int pathx=n;int pathy=m;int pathz=g;
            stack<cor> path;
            while(arr[pathx][pathy][pathz]>=2){
                path.push({pathx,pathy,pathz});
                pathx-=dx[arr[path.top().x][path.top().y][path.top().z]-2];
                pathy-=dy[arr[path.top().x][path.top().y][path.top().z]-2];
                pathz-=dz[arr[path.top().x][path.top().y][path.top().z]-2];
            }
            cout<<"(1,1,1)";
            while(!path.empty()){
                cout<<"->("<<path.top().x<<","<<path.top().y<<","<<path.top().z<<")";
                path.pop();
            }
            cout<<endl;
            return 0;
        }
        for(int i=0;i<6;i++){
            int newx=temp.x+dx[i];int newy=temp.y+dy[i];int newz=temp.z+dz[i];
            if(inbound(newx,newy,newz)){
                if(arr[newx][newy][newz]==0){
                    arr[newx][newy][newz]=i+2;
                    bfs.push({newx,newy,newz});
                }
            }
        }
    } 
    cout<<"no route\n";



    return 0;
}
