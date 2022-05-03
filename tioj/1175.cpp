#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    set<int> s;
    while(n--){
        int a;cin>>a;
        s.insert(a);
        auto it = s.upper_bound(a);
        if(it!=s.end()) s.erase(it);
    }
    cout<<s.size()<<endl;







    return 0;
}
