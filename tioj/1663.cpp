#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    while(cin>>t){
        int a,b;cin>>a>>b; 
        if(t==1) cout<<a+b<<endl;
        if(t==2) cout<<a-b<<endl;
        if(t==3) cout<<a*b<<endl;
        if(t==4) cout<<a%b<<endl;
    }
    return 0;
}