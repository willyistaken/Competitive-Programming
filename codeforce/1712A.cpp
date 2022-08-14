#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int ans=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a>k && i<k) ans++; 
        }
        cout<<ans<<"\n";
    }







    return 0;
}