#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set<pair<int,int> > s;
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        if(a>b) swap(a,b);
        s.insert({a,b});
    }
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        if(a>b) swap(a,b);
        if(s.count({a,b})){
            cout<<"yes\n";
        }else{
            cout<<"no\n";
        }
    }



    return 0;
}