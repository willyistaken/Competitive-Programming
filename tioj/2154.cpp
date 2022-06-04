#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    bitset<26> now;
    now.set();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        bitset<26> exist;
        exist.reset();
        for(auto i : s){
            exist[i-'a']=1;
        }
        now&=exist;
    }
    if(now.none()){
        cout<<7122<<endl;
    }else{
        cout<<(char)('a'+now._Find_first())<<endl;
    }






    return 0;
}