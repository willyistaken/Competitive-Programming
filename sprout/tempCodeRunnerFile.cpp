#include <bits/stdc++.h>
using namespace std;
void GetVal(int p,int q);
void mysolve(int t,int d,int l,int r){
    if(r-l<1) return;
    int mid = (t+d)/2;
    int maxind=0;int maxv=INT_MIN;
    for(int i= l;i<=r;i++){
        int querry = GetVal(mid,i);
        if(querry>maxv){
            maxind=i;
            maxv=querry;
        } 
    }
    mysolve(t,mid,l,maxind-1);
    Report(maxv);
    mysolve(mid+1,d,maxind+1,r);
};
void solve(int n,int m){
    mysolve(1,n,1,m);
}