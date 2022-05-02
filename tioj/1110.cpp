#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int count[26]={0};
        string s;cin>>s;
        int maxn=0;
        for(int i=0;i<n;i++){
            count[s[i]-'a']+=1;
            maxn=max(maxn,count[s[i]-'a']);
        }
        for(int i=0;i<26;i++){
            if(count[i]==maxn){
                cout<<(char)('a'+i);
            }
        }
        cout<<"\n";
    }







    return 0;
}