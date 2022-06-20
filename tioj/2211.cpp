#include <bits/stdc++.h>
#include "lib2211.h"
using namespace std;
int query(int n,int t){
    assert(t>=0);
    if(t==0) return n;
    else return Query(n,t);
}
int main() {
    int n = Init();
    int sqn = sqrt(n)-1;
    map<int,int> insq;
    insq.insert({1,0});
    for(int i=0;i<=sqn;i++){
        int q = query(1,i);
        if(q==1 && i){
            Report(query(1,i-1));
            return 0;
        }
        insq.insert({q,i});
    }
    int now = 2;
    while(true){
        int q = query(1,((sqn*now)%n));
        if(insq.count(q)){
            int loc = (sqn*now%n)-insq[q] -1;
            if(loc<0) loc+=n;
            assert(loc!=0);
            int ans = query(1,loc);
            //assert(query(ans,1)==1);
            Report(ans);
            return 0;
        }else{
            now+=1;
        }
    }
}