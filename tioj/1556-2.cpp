#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin>>n;
    ll ans=0;
    ll nextplace=0;
    for(ll i=1;i<=n;i=nextplace+1){
        ll prev = i;
        nextplace = (n/(n/i));
        ans+= (nextplace-prev+1)*(n/i);
    }
    cout<<ans-n<<"\n";
    return 0;
}
//second approach:數論分塊　慢很多．．．
