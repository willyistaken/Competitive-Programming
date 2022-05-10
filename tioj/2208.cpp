#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
struct st{
    int x;
    int y;
    int t;
};
int n,m;
inline bool inbound(int x,int y){
    return (x>=0 && x<n && y>=0 && y<m);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    bool arr[n][m]={{0}};
    int q,p;cin>>q>>p;
    int a,b;cin>>a>>b;
    int dx[8]={q,-q,0,0,p,-p,0,0};
    int dy[8]={0,0,q,-q,0,0,p,-p};
    bool ogarr[n][m]={{0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            ogarr[i][j]=arr[i][j];
        }
    }
    queue<st> bfs;
    arr[0][0]=1;
    bfs.push({0,0,0});
    while(!bfs.empty()){
        st temp = bfs.front();
        bfs.pop();
        if(temp.x+1==a && temp.y+1==b){
            int ans1=temp.t;
            queue<st> bfs2;
            ogarr[a-1][b-1]=1;
            bfs2.push({a-1,b-1,0});
            while(!bfs2.empty()){
                st temp2 = bfs2.front();
                bfs2.pop();
                if(temp2.x+1==n && temp2.y+1==m){
                    cout<<ans1+temp2.t<<endl;
                    return 0;
                }
                for(int j=0;j<8;j++){
                    int newx=temp2.x+dx[j];
                    int newy=temp2.y+dy[j];
                    if(inbound(newx,newy)){
                        if(ogarr[newx][newy]==0){
                            ogarr[newx][newy]=1;
                            bfs2.push({newx,newy,temp2.t+1});
                        }
                    }
                }
            }
            cout<<-1<<endl;
            return 0;
        }
        for(int i=0;i<8;i++){
            int newx=temp.x+dx[i];
            int newy=temp.y+dy[i];
            if(inbound(newx,newy)){
                if(arr[newx][newy]==0){
                    arr[newx][newy]=1;
                    bfs.push({newx,newy,temp.t+1});
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}