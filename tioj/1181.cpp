#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        map<char,bool> m;
        for(int i=0;i<12;i++){
            string s;cin>>s;
            for(int i=0;i<6;i++) {
                if(s[i]=='R' || s[i]=='G' ||s[i]=='B' ||s[i]=='Y'||s[i]=='P'){
                    m.insert({s[i],1});
                }
            }
        }
        cout<<m.size()<<endl;
    }
    return 0;
}