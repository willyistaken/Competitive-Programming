#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        int r,a;cin>>r;
        for(int i=1;i<n;i++){
            cin>>a;
            r=((r==1) ? 1:__gcd(r,a));
        }
        cout<<r<<endl;
    }







    return 0;
}