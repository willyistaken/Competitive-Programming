#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(int a,int b){
    int aans=0;
    int bans=0;
    while(a){
        aans+=1;
        a-=(a&-a);
    }
    while(b){
        bans+=1;
        b-=(b&-b);
    }
    return aans<bans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    stable_sort(arr,arr+n,comp);
    for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];






    return 0;
}