#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    ll g = sqrt(n);
    ll ans=0;
    for(int i=1;i<=g;i++) ans+= 2*(n/i);
    ans-=g*g;
    ans-=n;
    cout<<ans<<"\n";
    return 0;
}
//first approach: by symmetry and cool math