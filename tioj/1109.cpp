#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        while(n--){
            string s;cin>>s;
            if(n==m-1) cout<<s<<"\n";
        }
    }
    return 0;
}