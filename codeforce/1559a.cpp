#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
          int n;cin>>n;
    int ans;cin>>ans;
    for(int i=0;i<n-1;i++){
        int k;cin>>k;
        ans= (ans&k);
    }
    cout<<ans<<endl;  
    }

}