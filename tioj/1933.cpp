#include <bits/stdc++.h>
using namespace std;
struct guest{
    int x;
    int t;
};
bool compa(guest a,guest b){
    return a.x+a.t<b.x+b.t;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
      int n,l,c;cin>>n>>l>>c;
    guest arr[n];
    for(int i=0;i<n;i++){
        int x,t;cin>>x>>t;
        guest temp;
        temp.x = x;
        temp.t=  t;
        arr[i] = temp;
    }
    sort(arr,arr+n,compa);
    long long dp[n][2]={{0}};
    dp[0][1]=c-(arr[0].x+arr[0].t);
    dp[0][0]=0;
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        if(arr[i].x+arr[i].t>l){
            dp[i][1]=LONG_LONG_MIN;
        }else{
             int l=-1;
        int r=i;
        while(r-l>1){
            int mid = (r+l)>>1;
            if(arr[mid].x+arr[mid].t>arr[i].x){
                r=mid;
            }else{
                l=mid;
            }
        }
        if(l==-1){
            dp[i][1] = c-(arr[i].x+arr[i].t);
        }else{
            dp[i][1]=max(dp[l][1],dp[l][0])+c-(arr[i].x+arr[i].t);
        }  
        }   
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;  
    }












}
