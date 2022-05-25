#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int l,n,m;cin>>l>>n>>m;
    int realmap[n+1];
    for(int i=1;i<=n;i++){
        cin>>realmap[i];
    }
    int mmap[n+1];
    for(int i=1;i<=n;i++){
        mmap[i]=i;
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            mmap[j]=realmap[mmap[j]];
        }
    }
   string s;
   while(l--){
    cin>>s;
   string ans =s;
    for(int i=0;i<n;i++){
        ans[mmap[i+1]-1]=s[i];
    }
    cout<<ans<<endl;
   }


    return 0;
}