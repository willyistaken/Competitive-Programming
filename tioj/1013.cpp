#include <bits/stdc++.h>
using namespace std;
string maps ="******************...*.......**..***..*....*.*.*..**......*.**.**.***..**...**..**.****.....**..*.*..**....*..........**.....****.*...******.*.*........******************";
struct st{
    int x=0;
    int y=0;
    int t=0;
    int type=0;
};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int maparr[10][17];
void printa(){
    cout<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<17;j++){
            cout<<maparr[i][j];
        }
        cout<<endl;
    }
}
int main() {
    
    for(int i=0;i<10;i++){
        for(int j=0;j<17;j++){
            maparr[i][j]=(maps[17*i+j]=='*');
        }
    }
    int fx,fy;cin>>fx>>fy;
    int t;cin>>t;
    int ogt=t;
    int sx,sy,ex,ey;cin>>sx>>sy>>ex>>ey;
    queue<st> bfs;
    st temp;
    bfs.push(st{fx,fy,1,1});
    maparr[fx][fy]=1;
    for(int i=2;i<=t;i++){
        while(bfs.front().t<i){
        temp = bfs.front(); 
        bfs.pop();
       
        for(int j=0;j<4;j++){
            if(!(maparr[temp.x+dx[j]][temp.y+dy[j]] || (temp.type && (temp.x+dx[j]==ex && temp.y+dy[j]==ey)))){
                bfs.push(st{temp.x+dx[j],temp.y+dy[j],i,temp.type});
                maparr[temp.x+dx[j]][temp.y+dy[j]]=1;
            }
        }   
        
        } 
    }
    bfs.push(st{sx,sy,t,0});
    if(maparr[sx][sy]){
        cout<<"Help!\n"<<endl;
        return 0;
    }
    maparr[sx][sy]=1;
    while(!bfs.empty()){
        ++t;
        while(!bfs.empty() && bfs.front().t<t){
            temp = bfs.front();
            bfs.pop();
            //maparr[temp.x][temp.y]=1; 
            if(temp.x==ex && temp.y==ey){ 
                cout<<temp.t-ogt<<endl;
                return 0;
            }
            for(int j=0;j<4;j++){
                if(!(maparr[temp.x+dx[j]][temp.y+dy[j]] || (temp.type && (temp.x+dx[j]==ex && temp.y+dy[j]==ey)))){
                bfs.push(st{temp.x+dx[j],temp.y+dy[j],temp.t+1,temp.type});
                 maparr[temp.x+dx[j]][temp.y+dy[j]]=1;
            }
            } 
        }
    }
    cout<<"Help!\n";
}