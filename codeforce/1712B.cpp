#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n%2){
            cout<<1<<" ";
            for(int i=2;i<=n;i++){
                cout<<(i^1)<<" ";
            }
        }else{
            for(int i=0;i<n;i++){
                cout<<(i^1)+1<<" ";
            }
        }
        cout<<"\n";
    }







    return 0;
}