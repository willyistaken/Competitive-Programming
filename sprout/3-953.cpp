#include <bits/stdc++.h>
using namespace std;

int main(){
    string c;cin>>c;
    string s;cin>>s;
    int count[26]={0};
    for(int i=0;i<c.size();i++){
        count[(c[i]-'a'+s[i]-'a')%26]+=1;
    }
    for(int i=0;i<25;i++){
        cout<<count[i]<<" ";
    }
    cout<<count[25];
}