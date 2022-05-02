#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,t;cin>>m>>n>>t;
    int arrn[n]={0};
    int arrm[m]={0};
    set<pair<int,int> > s; 
    for(int i=0;i<t;i++){
        int r,c;cin>>r>>c; 
        arrm[r]+=1;
        arrn[c]+=1;
        s.insert(make_pair(r,c));
    }
    

}