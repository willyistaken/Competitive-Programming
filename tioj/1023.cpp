#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    while(cin>>m){
        int r[m];int b[m];
        for(int i=0;i<m;i++){
            cin>>r[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(r,r+m,greater<int>());
        sort(b,b+m,greater<int>());
        long long ans=0;
        for(int i=0;i<m;i++){
           ans+= r[i]*b[i];
        }
        cout<<ans<<endl;
    }
}
