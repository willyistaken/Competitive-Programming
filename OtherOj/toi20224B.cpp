#include <bits/stdc++.h>
using namespace std;


int main(){
    int x,y;cin>>x>>y;
    if(x==0){
        cout<<-1<<endl;
        return 0;
    }
    int xcard[x];
    int ycard[y];
    for(int i=0;i<x;i++){
        cin>>xcard[i];
    }
    for(int j=0;j<y;j++){
        cin>>ycard[j];
    }
    sort(xcard,xcard+x);
    sort(ycard,ycard+y);
    if(y==0){
        cout<<xcard[0]<<endl;
        return 0;
    }
    long long xwin=0;
    long long ywin=0;
    for(int i=0;i<x;i++){
        int rk = upper_bound(ycard,ycard+y,xcard[i])-ycard;
        int lk = lower_bound(ycard,ycard+y,xcard[i])-ycard;
        xwin+=lk;
        ywin+=(y-rk);
    }
    int l=-1;int r=x;
    while(r-l>1){
        int mid=l+((r-l)/2);
        int rj = upper_bound(ycard,ycard+y,xcard[mid])-ycard;
        int lj = lower_bound(ycard,ycard+y,xcard[mid])-ycard;
        if(xwin+lj>ywin+(y-rj) && xwin<=(1LL*lj*x)){
            r=mid;
        }else{
            l=mid;
        }
    }
    if(r<x){
        cout<<xcard[r]<<endl;
    }else{
        cout<<-1<<endl;
    }
}