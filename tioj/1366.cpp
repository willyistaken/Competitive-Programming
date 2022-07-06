#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(string a,string b){
    int as=0;
    int bs=0;
    for(auto i : a) as+=i-'0';
    for(auto i : b) bs+=i-'0';
    return as<bs;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        string arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        stable_sort(arr,arr+n,comp);
        for(auto i : arr) cout<<i<<" ";
        cout<<"\n";
    }




    return 0;
}
