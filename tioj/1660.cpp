#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool p(string &s){
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while(getline(cin,s)){
        if(p(s)){
            cout<<"palindrome\n";
        }else{
            cout<<"not palindrome\n";
        }
    }







    return 0;
}