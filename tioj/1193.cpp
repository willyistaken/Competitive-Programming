#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const g = (1LL<<42);
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m && (n||m)){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
       if(ans>g) ans%=m;//mod is a expensive operation，don't do it until completely neccesary
    }
    cout<<ans%m<<endl;
    }






    return 0;
}