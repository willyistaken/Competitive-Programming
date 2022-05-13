#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n,m;cin>>n>>m;
    pair<int,int> arr[n];
    int c=0;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b; 
        arr[i]={a,b};
        c+=b;
    }
    if(c<m){
        cout<<"so sad\n";
        continue;
    }
    sort(arr,arr+n);
    long long sum=0;
    int cur=0;
    while(m){
        if(arr[cur].second>m){
            sum+=arr[cur].first*m;
            m=0;
        }else{
            sum+=arr[cur].first*arr[cur].second;
            m-=arr[cur].second;
        }
        ++cur;
    }
    cout<<sum<<"\n";
    }




    return 0;
}