#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n &&n){
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,greater<int>());
    long long ans=(arr[0]<<1)-1;
    for(int i=1;i<n;i++){
        ans+=arr[i];
    }
    cout<<ans+2<<"\n";  
    }
 
}