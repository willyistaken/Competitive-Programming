#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    double ans=1;
    for(int i=0;i<n;i++){
        int maxn=-1;
        for(int j=0;j<n;j++){
            int k;cin>>k;
            maxn = max(maxn,k);
        }
        ans*=(double)maxn/100;
    }
    cout<<setprecision(2)<<fixed<<ans*100<<"\n";







    return 0;
}