#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int a,b,c;cin>>a>>b>>c;
        int sw = b*b-(4*a*c);
        if(sw<0){
            cout<<"No\n";
        }else if(floor(sqrt(sw))==sqrt(sw)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}