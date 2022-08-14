#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int arr[n];
        pair<int,int> minarr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            minarr[i] = {arr[i],i};
        }
        sort(minarr,minarr+n);
        for(int i=0;i<k;i++) arr[minarr[i].second]=1e9;
        int minfroml[n];
        int minfromr[n];
        minfroml[0]=arr[0];
        minfromr[n-1]=arr[n-1];
        for(int i=1;i<n;i++) minfroml[i] = min(minfroml[i-1],arr[i]);
        for(int i=n-2;i>=0;i--) minfromr[i] = min(minfromr[i+1],arr[i]);
        int ansm=minfromr[0];
        for(int i=0;i<n-2;i++){
            ansm = max(min(min(arr[i],arr[i+1]),2*minfromr[i+2]),ansm);
        }
        ansm = max(minfroml[n-1],ansm);
        for(int i=n-1;i>=2;i--){
            ansm = max(min(min(arr[i],arr[i-1]),2*minfroml[i-2]),ansm);
        }
        cout<<ansm<<"\n";
    }







    return 0;
}