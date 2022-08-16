#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    if(n%2){
        if(n==1){
            cout<<"Yes\n1\n";
            return 0;
        }
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    cout<<n;
    int g = 1;
    for(int i=1;i<n;i++){
        cout<<" "<<(n+(g*i))%n;
        g*=-1;
    }
    cout<<"\n";






    return 0;
}