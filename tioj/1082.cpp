#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n and n){
    if(n==1){
        int a,b;cin>>a>>b; 
        cout<< ((a && b) ? -1:0) <<endl;
        continue;
    }
    unsigned sum=0;
    bool notb=1;
    bool notw=1;
    int minw=INT_MAX;
    int minb=INT_MAX;
    for(int i=0;i<n;i++){
        int b,w;cin>>b>>w; 
        if(w>b){
           notw=0;
           sum+=b; 
        }else if(b>w){
            notb=0;
            sum+=w;  
        }else if(notw){
            notw=0;
            sum+=w;
        }else{
            notb=0;
            sum+=b;
        }
       minw= min(minw,w-b);
       minb= min(minb,b-w);
    }
    if(notb){
        sum+=minw;
    }
    if(notw){
        sum+=minb;
    }
    cout<<sum<<endl;
    }
}