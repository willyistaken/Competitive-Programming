#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(b,b+m);
    int ans=0;
    for(int i=0;i<n;i++){
       int place = lower_bound(b,b+m,a[i])-b;
       ans+=(!((place+m)%2) && a[i]!=b[place]);
    }
    cout<<ans<<endl;





    return 0;
}