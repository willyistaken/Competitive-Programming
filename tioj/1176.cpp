#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    stack<pair<int,int> > mono;
    int ans[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=n-1;i>=0;i--){ 
        if(mono.empty()){
            ans[i]=n-i-1;
        }else{
            ans[i]=mono.top().second-i;
        }
        while(!mono.empty() && mono.top().first<arr[i]){
            ans[i]=mono.top().second-i;
            mono.pop();
        }
        if(mono.empty()){
            ans[i]=n-i-1;
        }else{
            ans[i]=mono.top().second-i;
        }
        mono.push({arr[i],i});
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;






    return 0;
}