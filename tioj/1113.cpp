#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while(cin>>s){
    sort(s.begin(),s.end());
    cout<<s<<endl;
    string j=s;
    next_permutation(s.begin(),s.end());
    while(s!=j){
        cout<<s<<endl;
        next_permutation(s.begin(),s.end());
    }
    cout<<endl;
    }
    return 0;
}