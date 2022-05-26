#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[3];
    while(n--){
       cin>>arr[0]>>arr[1]>>arr[2];
       sort(arr,arr+3);
       if(arr[0]<=0){
           cout<<"no\n";
           continue;
       }
       if(  (1ULL*arr[0]*arr[0]) + (1ULL*arr[1]*arr[1]) == 1ULL*arr[2]*arr[2]){
           cout<<"yes\n";
       }else{
           cout<<"no\n";
       }
    }







    return 0;
}