#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
       string target;cin>>target;
    target = 'h'+target;
    target+='h';
    bool can=1;
    for(int i=1;i<target.size()-1;i++){
        if(target[i-1]!=target[i] && target[i]!=target[i+1]){
            can=0;
            break;                
        }
    }
    cout<<vector<string>{"Yes\n","No\n"}[!can];  
    }
   
}