#include <bits/stdc++.h>
using namespace std;
int ans[100005][3][3];
const int mod = 1000007;
int main(){
    ans[1][0][0]=1;
    ans[1][0][1]=0;
    ans[1][0][2]=0;
    ans[1][1][0]=0;
    ans[1][1][1]=1;
    ans[1][1][2]=0;
    ans[1][2][0]=0;
    ans[1][2][1]=0;
    ans[1][2][2]=1;
    for(int i=2;i<=100004;i++){
        ans[i][0][0]=(1LL*ans[i-1][0][0]+1LL*ans[i-1][0][1]+1LL*ans[i-1][0][2])%mod;
        ans[i][0][1]=(1LL*ans[i-1][0][0]+1LL*ans[i-1][0][1])%mod;
        ans[i][0][2]=(1LL*ans[i-1][0][0]+1LL*ans[i-1][0][2])%mod;
        ans[i][1][0]=(1LL*ans[i-1][1][0]+1LL*ans[i-1][1][1]+1LL*ans[i-1][1][2])%mod;
        ans[i][1][1]=(1LL*ans[i-1][1][0]+1LL*ans[i-1][1][1])%mod;
        ans[i][1][2] = (1LL*ans[i-1][1][0]+1LL*ans[i-1][1][2])%mod;
        ans[i][2][0]=(1LL*ans[i-1][2][0]+1LL*ans[i-1][2][2]+1LL*ans[i-1][2][1])%mod;
        ans[i][2][2]=(1LL*ans[i-1][2][0]+1LL*ans[i-1][2][2])%mod;
        ans[i][2][1] = (1LL*ans[i-1][2][0]+1LL*ans[i-1][2][1])%mod;
    }


     int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<  (1LL*ans[n][0][0]+ans[n][0][1]+ans[n][0][2]+ans[n][1][0]+ans[n][1][1]+ans[n][2][0]+ans[n][2][2])%mod<<endl;
    } 
/*     for(int n=1;n<=1000;n++){
        cout<<  (1LL*ans[n][0][0]+ans[n][0][1]+ans[n][0][2]+ans[n][1][0]+ans[n][1][1]+ans[n][2][0]+ans[n][2][2])%mod<<endl;
    } */

}