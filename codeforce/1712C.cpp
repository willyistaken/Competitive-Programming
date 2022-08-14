#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        bool setzero[n+1]={0};
        int inright[n+1]={0};
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int border=n-1;
        for(;border>=0;border--){
            if(!inright[arr[border]]) inright[arr[border]]=border;
            if( border>0 && arr[border-1]>arr[border]) break;
        }
        int ans=0;
        //cout<<border<<"\n";
        for(int i=0;i<border;i++){
            if(setzero[arr[i]]) continue;
            if(inright[arr[i]]){
               border = max(inright[arr[i]],border); 
            }
            ans++;
            setzero[arr[i]]=1;
        }
        cout<<ans<<"\n";
    }






    return 0;
}