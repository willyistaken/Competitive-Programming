#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int a,int b,int n){
    if(b==0) return n;
    n+=a/b;
    return solve(b,a%b,n);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b;
    while(cin>>a>>b) cout<<solve(a,b,0)<<endl;
    return 0;
}