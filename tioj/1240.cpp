#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
bool check(int n,int* arr,int k){
    vector<int> s;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            s.push_back(arr[i]);
        }else{
        int l=-1,r=s.size();
        while(r-l>1){
            int mid=(l+r)/2;
            if(s[mid]<arr[i]){
                r=mid;
            }else{
                l=mid;
            }
        }
        if(r==s.size()){
            s.push_back(arr[i]);
        }else{
            s[r]=arr[i];
        }
        } 
        if(s.size()>k) return false;
    }
    return true; 
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int l=0;int r=n;
    while(r-l>1){
        int mid=(l+r)/2;
        if(check(n,arr,mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r<<"\n";






    return 0;
}