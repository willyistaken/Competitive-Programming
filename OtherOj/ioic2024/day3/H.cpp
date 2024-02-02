#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
void solve(){
    int n,k;cin>>n>>k;
    if(k>=(n/2)+(n%2)){
            int g = k-(n/2);
            cout<<"YES\n";
            cout<<g<<" ";
            for(int i=2;i<=n;i++) cout<<1-(i%2)<<" ";
            cout<<"\n";
    }else cout<<"NO\n";
}
signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
