#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6+5;
int u[MAXN];
int x[MAXN];
vector<int> prime;
void init(){
    u[1]=1;
    x[1]=1;
    for(int i=2;i<MAXN;i++){
        if(!x[i]){
            prime.push_back(i);
            u[i]=-1;
            x[i]=i;
        }
        for(int k=0;k<prime.size()&&1LL*prime[k]*i<MAXN;k++){
            if(prime[k]<=x[i]){
                x[i*prime[k]] = prime[k];
                u[i*prime[k]] = (prime[k]==x[i])?(0):(u[i]*u[prime[k]]);
            }else{
                break;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    ll n;cin>>n;
    ll ans=0;
    for(ll i=2;i*i<=n;i++){
        ans+=(-u[i]*(n/(i*i)));
    }
    cout<<ans<<"\n";






    return 0;
}