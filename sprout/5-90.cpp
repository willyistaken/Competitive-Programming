#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){

    int n,m;cin>>n>>m;
    int cap[n];int ripesum[m+1]={0};
    for(int i=0;i<n;i++){
        cin>>cap[i];
    }
    for(int i=1;i<m+1;i++){
        cin>>ripesum[i];
    }
    sort(cap,cap+n,greater<int>());
    sort(ripesum,ripesum+m,less<int>());
    for(int i=1;i<m+1;i++){
        ripesum[i] = ripesum[i]+ripesum[i-1];
        cout<<ripesum[i]<<" ";
    }
    int upperlimit = m;
    for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
         
   }   
    }
    
    
    }
}