#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
    ll t;
    ll h;
    ll r;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        st dp[n];
        dp[0].h = arr[0];
        dp[0].r = 0;
        dp[0].t = 0;
        for(int i=1;i<n;i++){
            if(arr[i]-dp[i-1].r>dp[i-1].h){
                dp[i].t = dp[i-1].t+(arr[i]-dp[i-1].r-dp[i-1].h);
                dp[i].r = dp[i-1].r+(arr[i]-dp[i-1].r-dp[i-1].h);
                dp[i].h = dp[i-1].h;
            }else if(arr[i]-dp[i-1].r==dp[i-1].h){
                dp[i] = dp[i-1];
            }else{
                dp[i].t = dp[i-1].t + (dp[i-1].h-arr[i]+dp[i-1].r);
                dp[i].r = dp[i-1].r;
                dp[i].h = arr[i]-dp[i-1].r;
            }
        }
        cout<<dp[n-1].t+abs(dp[n-1].h)<<endl;
    }

    return 0;
}