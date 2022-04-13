#include <bits/stdc++.h>
using namespace std;

vector<vector<short> > gansarr[1024];
vector<vector<short> > fansarr[1024];

void g(int n){
    if(n==2){
        vector<vector<short> > temp(2,vector<short>(2,0));
        gansarr[2] = temp;
        gansarr[2][0][0]=1;
        gansarr[2][0][1]=2;
        gansarr[2][1][0]=2;
        gansarr[2][1][1]=1;
        return ;
    }
    if(gansarr[n].empty()){
        g(n/2);
        vector<vector<short> > temp(n,vector<short>(n,0));
        gansarr[n]= temp; 
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                gansarr[n][i][j]=gansarr[n/2][i][j];
                gansarr[n][i+n/2][j+n/2]=gansarr[n/2][i][j];
                gansarr[n][i+n/2][j]=gansarr[n/2][i][j]+n/2;
                gansarr[n][i][j+n/2]=gansarr[n/2][i][j]+n/2;
            }
        }

    }else{
        return;
    }
}

void f(int n){
 if(n==2){
    vector<vector<short> > temp(2,vector<short>(2,0));
    fansarr[2] = temp; 
    fansarr[2][0][0]=1;
    fansarr[2][0][1]=2;
    fansarr[2][1][0]=3;
    fansarr[2][1][1]=1;
    return ;   
 }
 if(fansarr[n].empty()){
     f(n/2);
     g(n/2);
     vector<vector<short> > temp(n,vector<short>(n,0));
     fansarr[n]= temp; 
    for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                fansarr[n][i][j]=fansarr[n/2][i][j];
                fansarr[n][i+n/2][j+n/2]=fansarr[n/2][i][j];
                fansarr[n][i+n/2][j]=gansarr[n/2][i][j]+n-1+n/2;
                fansarr[n][i][j+n/2]=gansarr[n/2][i][j]+n-1;
            }
        }
 }else{
     return ;
 }
}

// void Report(int j){
//     cout<<j<<" ";
// }
void solve(int N){
    f(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Report((int) fansarr[N][i][j]);
        }
        //cout<<endl;
    }
}

// int main(){
//     int n;cin>>n;
//     solve(n);
// }