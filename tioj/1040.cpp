#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    for(int j=0;j<n;j++){
    int p,q;cin>>p>>q;
    cout<<p<<"/"<<q<<" = ";
    if(p==0){
        cout<<0;
        return 0;
    }
    if((p%q==0&&p>=q)){
        cout<<p/q;
        return 0;
    }
    int time=0;
    while(p%q!=0 || p<q){
        int m=(p-(p%q));
        cout<<m/q<<"+1/";
        int j=p;
        p=q;
        q=j-m;
        if(p%q!=0){
            cout<<"{";time++;
        }
        
    }
    cout<<p/q;
    for(int i=0;i<time;i++){
        cout<<"}";
    }
    puts("");
    }
}