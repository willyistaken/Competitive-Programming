#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==0) {
            cout<<1<<endl;
            continue;
        }
        int ans[n];
        ans[0]=0;
        ans[1]=1;
        for(int i=2;i<n;i++) ans[i] = 2*ans[i-1]+3*ans[i-2];
        cout<<3*ans[n-1]<<endl;
    }






    return 0;
}