#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b,c; 
    while(cin>>a>>b>>c){
        long long sum = a+b+c; 
        if(sum-a>a && sum-b>b && sum-c>c){
            cout<<"SAFE\n";
        }else{
            cout<<"BYE\n";
        }
    }







    return 0;
}