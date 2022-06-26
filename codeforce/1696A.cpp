#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;int z;cin>>z;
        int maxn =INT_MIN;
        for(int i=0;i<n;i++){
            int k;cin>>k;
            maxn = max(maxn,k|z);
        }
        cout<<maxn<<endl; 
    }








    return 0;
}