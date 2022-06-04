#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        if(n%3==0){
            if(n%27==0){
                cout<<"sad\n";
            }else{
                if(n%9==0){
                    cout<<"happy\n";
                }else{
                    cout<<"sad\n";
                }
            }
        }else{
            cout<<"happy\n";
        }
    }







    return 0;
}