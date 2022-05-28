#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while(cin>>s){
    for(int i=0;i<s.size();i++){
        if(s[i]!='0'){
            cout<<s.size()-i<<endl;
            break;
        }
    }
    }






    return 0;
}