#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6;

int power(int n,int c){
    int r=1;
    while(c){
        if(c&1){
            r = (1LL*n*r)%mod;
        }
        c>>=1;
        n=(1LL*n*n)%mod;
    }
    return r%mod;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,c,d;cin>>a>>b>>c>>d;
    int ans=0;
    for(int i=a;i<=d;i+=b){
        ans += power(i,c);
        ans%=mod;
    }
    cout<<ans<<endl;





    return 0;
}