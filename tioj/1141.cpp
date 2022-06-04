#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    ll ans=arr[0]*arr[0];
    for(int i=1;i<n;i++){
        ans+=(arr[i]-arr[i-1])*(arr[i]-arr[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}