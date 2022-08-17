#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long h;
    string type,g;
    while(cin>>h>>type>>g){
        ll n = h; 
        if(n%2){
            if(type[0]=='R'){
                cout<<0<<"\n";
            }
            if(type[0]=='A'){
                cout<<(long long)((n*n*n - n)/24)<<"\n";
            }
            if(type[0]=='O'){
                cout<<(long long)((n*n*n - 4*n*n +3*n)/8)<<"\n";
            }
        }else{
            if(type[0]=='R'){
                cout<<(long long)((n*n-2*n)/2)<<"\n";
            }
            if(type[0]=='A'){
                cout<<(long long)((n*n*n-6*n*n+8*n)/24)<<"\n";
            }
            if(type[0]=='O'){
                cout<<(long long)((n*n*n-6*n*n+8*n)/8)<<"\n";
            }
        }
    }







    return 0;
}

//int128 is love