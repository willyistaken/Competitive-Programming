#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n%2 || n<=3) {
            cout<<-1<<endl;
            continue;
        }
        cout<<(n/6)+((n%6)!=0)<<" "<<(n/4)<<endl;
    }







    return 0;
}