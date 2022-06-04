#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        if(n-(n&-n)){
            cout<<(n&-n)<<endl;
        }else{
            if(n!=1) cout<<(n&-n)+1<<endl;
            else cout<<3<<endl;
        }
    }







    return 0;
}