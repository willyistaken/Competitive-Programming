#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n+1]={0};
        for(int i=1;i<=n;i++){
            int k;cin>>k;
            arr[i]=k-arr[i-1];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(1LL*arr[i]*arr[i-1]<0) ans+=1; 
        }
        cout<<ans<<"\n";
    }
    







    return 0;
}