#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;

    while(t--){
        int n,m;cin>>n>>m;
        set<int> s;
        for(int i=0;i<n-1;i++) {
            int a;cin>>a;
            s.insert(a);
        }
        auto it =s.upper_bound(m); cout<<*it<<" ";--it;cout<<*it<<"\n";
    }







    return 0;
}