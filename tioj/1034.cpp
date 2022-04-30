#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
// this is a wrong approach --> why?
//I use floyd-warshall algorithm but the problem is in the one shot list, I reason that the best way to shoot down an enemy is the biggest of the path, but it will seems that I am wrong, although I don't know why
//the way to do this is by emumerate every possible place to shoot down the enemy 
// or the problem lies in the unusual use of floyd warshall [l,r] i believe this is also a reason
/*
int dx[5]={1,-1,0,0,0};
int dy[5]={0,0,1,-1,0};
int n;
inline bool inbound(int x,int y){
    if(x<=n && x>=1){
        if(y<=n && y>=1){
            return true;
        }
    }
    return false;
}

pair<int,int> e[21][21][21][21];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    
    fill_n(&e[0][0][0][0],194481,make_pair((int)1e9,-1));
    int bing[n+1][n+1];
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cin>>bing[i][j];
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            for(int k=0;k<5;k++){
                if(inbound(i+dx[k],j+dy[k])){
                    e[i][j][i+dx[k]][j+dy[k]].first=bing[i][j]+bing[i+dx[k]][j+dy[k]]; 
                    if(dx[k]==0 && dy[k]==0) e[i][j][i+dx[k]][j+dy[k]].first-=bing[i][j];
                    e[i][j][i+dx[k]][j+dy[k]].second=max(bing[i][j],bing[i+dx[k]][j+dy[k]]);
                }
            }
        }
    }    
\\this use a [l,r] floyd-warshall which is very unusal and cause me a WA 
    for(int kx=1;kx<n+1;kx++){
        for(int ky=1;ky<n+1;ky++){
            for(int ix=1;ix<n+1;ix++){
                for(int iy=1;iy<n+1;iy++){
                    for(int jx=1;jx<n+1;jx++){
                        for(int jy=1;jy<n+1;jy++){ 
                        for(int willy=0;willy<5;willy++){
                            if(inbound(kx+dx[willy],ky+dy[willy])){
                                if(e[ix][iy][jx][jy].first-e[ix][iy][jx][jy].second > e[ix][iy][kx][ky].first+e[kx+dx[willy]][ky+dy[willy]][jx][jy].first-max(e[ix][iy][kx][ky].second,e[kx+dx[willy]][ky+dy[willy]][jx][jy].second)){
                                    e[ix][iy][jx][jy].first=e[ix][iy][kx][ky].first+e[kx+dx[willy]][ky+dy[willy]][jx][jy].first;
                                    e[ix][iy][jx][jy].second=max(e[ix][iy][kx][ky].second,e[kx+dx[willy]][ky+dy[willy]][jx][jy].second);
                            }  
                            }
                            }


                        }
                    }
                }
            }
        }
    }
     int q;cin>>q;
    for(int i=0;i<q;i++){
       int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
       cout<<e[x1][y1][x2][y2].first-e[x1][y1][x2][y2].second<<endl;
    } 




    return 0;
}
*/

int dx[5]={1,-1,0,0,0};
int dy[5]={0,0,1,-1,0};
int n;
inline bool inbound(int x,int y){
    if(x<=n && x>=1){
        if(y<=n && y>=1){
            return true;
        }
    }
    return false;
}

int e[21][21][21][21];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    
    fill_n(&e[0][0][0][0],194481,(int)1e9);
    int bing[n+1][n+1];
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cin>>bing[i][j];
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            for(int k=0;k<5;k++){
                if(inbound(i+dx[k],j+dy[k])){
                    e[i][j][i+dx[k]][j+dy[k]]=bing[i+dx[k]][j+dy[k]]; 
                    if(dx[k]==0 && dy[k]==0)  e[i][j][i+dx[k]][j+dy[k]]=0; 
                }
            }
        }
    }    

    for(int kx=1;kx<n+1;kx++){
        for(int ky=1;ky<n+1;ky++){
            for(int ix=1;ix<n+1;ix++){
                for(int iy=1;iy<n+1;iy++){
                    for(int jx=1;jx<n+1;jx++){
                        for(int jy=1;jy<n+1;jy++){ 
                                if(e[ix][iy][jx][jy] > e[ix][iy][kx][ky]+e[kx][ky][jx][jy]){
                                    e[ix][iy][jx][jy]=e[ix][iy][kx][ky]+e[kx][ky][jx][jy];
                            }
                


                        }
                    }
                }
            }
        
        }
    }
     int q;cin>>q;
    for(int i=0;i<q;i++){
       int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
       int minn=INT_MAX;
       for(int g=1;g<n+1;g++){
           for(int h=1;h<n+1;h++){
               minn = min(minn,e[x1][y1][g][h]+e[g][h][x2][y2]+bing[x1][y1]-bing[g][h]); 
           }
       }
       cout<<minn<<endl;
    } 




    return 0;
}