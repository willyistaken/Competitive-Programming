#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        ll ans = ((n*n + n)/2)*m + ((m*m+m)/2) - m;
        cout<<ans<<endl;
    }







    return 0;
}