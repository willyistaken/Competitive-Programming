#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    ll sum[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    ll dp[n+1]={0};
    deque<int> slope;
    slope.push_back(n);
    for(int i=n-1;i>=1;i--){
             
    }




    return 0;
}