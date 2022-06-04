#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        ll sum[n+1]={0};
        for(int i=1;i<=n;i++){
            cin>>sum[i];
            sum[i]+=sum[i-1];
        }
        if(k<n){
            ll maxn=0;
            for(int i=k;i<=n;i++){
                maxn=max(maxn,sum[i]-sum[i-k]);
            }
            cout<<maxn+(1LL*k*k-k)/2<<endl;
        }else{
            cout<<sum[n]+(1LL*(k-1)*n)-(((1LL*n*n)-n)/2)<<endl;
        }


    }







    return 0;
}