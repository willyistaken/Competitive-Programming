#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const MOD = 1e9+7;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    n+=1;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=0;
    int sum[arr[0]+1]={0};
    sum[1]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=arr[i];j++){  
            sum[j] = sum[j]+sum[j-1];
            sum[j] = (sum[j]>=MOD) ?  sum[j]-MOD:sum[j];
            ans+=sum[j];
            ans = (ans>=MOD) ? ans-MOD:ans;
        }
    }
    cout<<ans<<endl;







    return 0;
}