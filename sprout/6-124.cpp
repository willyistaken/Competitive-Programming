#include <bits/stdc++.h>
using namespace std;
int inqx[4] = {0,1,0,1};
int inqy[4] = {0,0,1,1};
void split(int xtr, int ytr,int n,int X,int Y){
    vector<pair<int,int> > tobereport;
    if(n==2){
        for(int i=0;i<4;i++){
            if(X==xtr+inqx[i] && Y==ytr+inqy[i]){

            }else{
                tobereport.push_back(make_pair(xtr+inqx[i],ytr+inqy[i]));
            }
        }
        Report(tobereport[0].first,tobereport[0].second,tobereport[1].first,tobereport[1].second,tobereport[2].first,tobereport[2].second);  
    }else{
      int half = n/2;
    for(int i=0;i<4;i++){
        if( ((X-xtr)/half)==inqx[i] && ((Y-ytr)/half)==inqy[i] ){
            split(xtr+inqx[i]*half,ytr+inqy[i]*half,half,X,Y);
        }else{
            tobereport.push_back(make_pair((xtr+half-1+inqx[i]),(ytr+half-1+inqy[i])));
            split(xtr+inqx[i]*half,ytr+inqy[i]*half,half,(xtr+half-1+inqx[i]),(ytr+half-1+inqy[i]));
        }
    }
    Report(tobereport[0].first,tobereport[0].second,tobereport[1].first,tobereport[1].second,tobereport[2].first,tobereport[2].second);  
    }
    
}
void solve(int N,int X,int Y){
    split(1,1,N,X,Y);
}



