#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;cin>>q;
    while(q--){
        int i,j;cin>>i>>j;
        swap(arr[i],arr[j]);
    } 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" \n"[i==n-1];
    }

    }






    return 0;
}