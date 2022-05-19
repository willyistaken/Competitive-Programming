#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    pair<int,int> loc[26] = {{0,0}};
    for(int i=0;i<s.size();i++){
        if(loc[s[i]-'A'].first==0){
            loc[s[i]-'A'].first=i+1;
            loc[s[i]-'A'].second = i+1;
        }else{
            loc[s[i]-'A'].second = i+1;
        }
    }
    for(int i=0;i<26;i++){
        if(loc[i].first){
            cout<<(char)('A'+i)<<":"<<loc[i].first<<","<<loc[i].second<<endl;
        }
    }






    return 0;
}