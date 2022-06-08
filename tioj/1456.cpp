#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m){
    vector<pair<int,int> > arr;
    for(;m;m--){
        int a,b;cin>>a>>b;
        arr.push_back({a,b});
    }
    int loc[n+1];
    for(int i=1;i<=n;i++){
        int g;cin>>g;
        loc[g]=i;
    }
    bool no=0;
    for(auto i : arr){
        if(loc[i.first]>loc[i.second]){
            cout<<"NO\n";
            no=1;
            break;
        }
    }
    if(!no) cout<<"YES\n";
    }



    return 0;
}