#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        if(!i) ans=k;
        else ans = __gcd(ans,k);
    }
    cout<<ans<<"\n";
    return 0;
}