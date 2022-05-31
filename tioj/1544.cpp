#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool bigger(string &a,string &b){
    if(a.size()!=b.size()){
        return a.size()>b.size();
    }
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            return a[i]>b[i];
        }
    }
    assert(1==0);
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--){
        string a,b;
        cin>>a;
        cin>>b;
        if(bigger(a,b)){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }







    return 0;
}