#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        if(mp.count(s)) mp[s]=mp[s]+1;
        else mp.insert({s,1});
    }
    for(int i=0;i<m;i++){
        string s;cin>>s;
        cout<<((mp.count(s)) ? mp[s] : 0)<<endl;
    }






    return 0;
}