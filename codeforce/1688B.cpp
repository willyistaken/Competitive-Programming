#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=0;
        int low=INT_MAX;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a%2==0){
                ans+=1;
                low=min(low,(a&-a));
            }
        }
        if(ans==n){
            cout<<__lg(low)+ans-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }






    return 0;
}