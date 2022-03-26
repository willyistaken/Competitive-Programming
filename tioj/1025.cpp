#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
const int dx[9]={1,1,1,0,0,-1,-1,-1,0};
const int dy[9]={1,0,-1,1,-1,1,0,-1,0};
const int centralx[9]={1,1,1,4,4,4,7,7,7};
const int centraly[9]={1,4,7,1,4,7,1,4,7};
void printsudo(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" \n"[j==8];
        }
    }
} 
void solve(int n){
    if(n>80){
        printsudo();
    }
    bool possible[10]={1};
    possible[0]=0;
    int x=n/9;
    int y=n%9;
    if(arr[x][y]==0){
        for(int i=0;i<9;i++){
            possible[arr[x][i]]=0;
        }
        for(int i=0;i<9;i++){
            possible[arr[i][y]]=0;
        }
        for(int i=0;i<8;i++){
                possible[arr[centralx[(x-(x%3))+(y/3)]+dx[i]][centraly[(x-(x%3))+(y/3)]+dy[i]]]=0;
        }
        for(int i=1;i<10;i++){
            if(possible[i]){
                arr[x][y]=i;
                solve(n+1);
            }
        }
    }
}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>arr[i][j];
        }
    }
    solve(0);



}