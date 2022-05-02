#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    while(cin>>n && n){
        if(floor(sqrt(n))==sqrt(n)){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }
}