#include <bits/stdc++.h>
using namespace std;
struct node{
    node(int f,int s,int g):
        first{f},second{s},gen{g} {}
    int first;
    int second;
    int gen;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
       int w,h;cin>>w>>h;
    int arr[w][h];
    node start(0,0,0);
    for(int i=0;i<w;i++){
        string c;cin>>c;
        for(int j=0;j<h;j++){
            if(c[j]=='#') arr[i][j]=0;
            if(c[j]=='K'){
                arr[i][j]=3;
                start.first=i;
                start.second=j;
                start.gen=0;
            }
            if(c[j]=='.') arr[i][j]=1;
            if(c[j]=='@') arr[i][j]=2;
        }
    }

    queue<node> bfs;
    bfs.push(start);
    int end=0;
    bool pass=0;
    while(!bfs.empty()){
        if(arr[bfs.front().first][bfs.front().second]){
            if(arr[bfs.front().first][bfs.front().second]==2){
                end=bfs.front().gen;
                pass=1;
                break;
            }
            arr[bfs.front().first][bfs.front().second]=0;
            bfs.push(node(bfs.front().first+1,bfs.front().second,bfs.front().gen+1));
            bfs.push(node(bfs.front().first-1,bfs.front().second,bfs.front().gen+1));
            bfs.push(node(bfs.front().first,bfs.front().second+1,bfs.front().gen+1));
            bfs.push(node(bfs.front().first,bfs.front().second-1,bfs.front().gen+1));
        }
        bfs.pop();
    }
    if(pass){
        cout<<end<<endl;
    }else{
        cout<<"= =\"\n";
    }
 
    }
    
}