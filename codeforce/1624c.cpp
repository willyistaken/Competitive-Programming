#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
    bool yes[n]={0};
    bool no=0;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        if(!no){
                while(k>0){
            if(k>n){
                k/=2;
                continue;
            }
            if(yes[k-1]){
                k/=2;
                continue;
            }else{
                yes[k-1]=1;
                break;
            }
            
        }
        if(k==0){
            no=1;
        } 
        }
   
    }
    if(no){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    }
    
}