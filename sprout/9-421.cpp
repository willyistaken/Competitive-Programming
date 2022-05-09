#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){

    int n,m;cin>>n>>m;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(2*a>=m){
            s.insert(2*a);
            auto it = s.upper_bound(2*a);
            if(it!=s.end()) s.erase(it);
        }
        if(a>=m){
            s.insert(a);
            auto it = s.upper_bound(a);
            if(it!=s.end()) s.erase(it);
        }
    }
    cout<<s.size()<<endl;
    }





    return 0;
}