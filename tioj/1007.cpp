#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;cin>>a;
    while(a.size()>0){
        if(a[0]=='.'){
            cout<<0;
            a=a.substr(1,a.size()-1);
        }else{
            if(a[1]=='.'){
                cout<<1;
                
            }else{
                cout<<2;
            }
            a=a.substr(2,a.size()-2);
        }
    }
}