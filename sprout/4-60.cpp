#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d;

long long furtherst(long long m,long long t){
    long long maxr=0;
    for(long long i=0;i<=t;i++){
        long long totalq = m+d*i;
        long long forwardtime = min(totalq/c,t-i);
        long long dis = b*forwardtime + a*(t-i-forwardtime);
        maxr = max(dis,maxr);
    }
    return maxr;
}

int main(){
    cin>>a>>b>>c>>d;
    long long m,s,t;cin>>m>>s>>t;
    long long l=0;long long r=t+1;
    long long mid;
    while(r-l>1){
        mid = (l+r)/2;
        if(furtherst(m,mid)>=s){
            r=mid;
        }else{
            l=mid;
        }
    }
    if(r<=t){
        cout<<"Yes\n"<<r<<endl;
    }else{
        cout<<"No\n"<<furtherst(m,t)<<endl;
    }
}