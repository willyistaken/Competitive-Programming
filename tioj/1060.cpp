#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int hr[6]={-1,-1,2,5,5,2};
inline int h(int y){
    if(y<0) return -1;
    return hr[y%6];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int f[90005];
    f[0]=2;
    f[1]=3;
    f[2]=1;
    f[3]=-1;
    f[4]=-1;
    for(int i=5;i<=90000;i++){
       f[i]=f[i-1]-h(i);
    }
    int nf[305];
    nf[1]=1;
    for(int i=2;i<=300;i++){
        nf[i]=f[i*i-1]-i*i+1;
    }
    int n;cin>>n;
    if(n<0){
        cout<<nf[-n]<<endl;
    }else{
        cout<<f[n]<<endl;
    }


    return 0;
}



/*
h(y): 
if y<0:-1;
else if(y%6==0 or 1): -1
        y%6==2 or 5): 2
        y%6==3 or 4):  5
g(y):
    def

f(x):
  x<-1:f(x^2-1)-x^2+1
  x==2 or -1: 1
  x==0 2
  x==1 3
   x=3 or 4 : -1
   x>=5 : def


*/