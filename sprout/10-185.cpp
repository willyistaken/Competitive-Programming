//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    ll c[n+1];
    ll sum[n+1];
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        sum[i]=sum[i-1]+c[i];
    } 
     
    return 0;
}