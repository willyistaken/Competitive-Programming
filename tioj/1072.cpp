#include <bits/stdc++.h>
using namespace std;

int main(){
     int n;
     while(cin>>n&&n){
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr,arr+n,greater<pair<int,int> >());
    int sum=0;
    int maxans=-1;
    for(int i=0;i<n;i++){
        sum+=arr[i].second;
        maxans = max(maxans,sum+arr[i].first);
    }
    cout<<maxans<<endl;   
     }    
    
}