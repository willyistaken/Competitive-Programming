#include <bits/stdc++.h>
using namespace std;
const int  mod = 1000007;

void pascal(vector<vector<int> > &c,int m){
    c[1][1]=1;
    c[1][0]=1;
    for(int i=2;i<=m;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                c[i][j]=1;
            }else{
              c[i][j]=(1LL*c[i-1][j-1]+c[i-1][j])%mod;   
            }
           
        }
    }    
}
int main(){
    int t;cin>>t;
    while(t--){

    int n,m;cin>>n>>m;
    vector<vector<int> > c( m+1 , vector<int>(m+1,0));
    int dp[m+1]={0};
    pascal(c,m);
    int arr[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=m;i++){
        long long ans=1;
        for(int j=1;j<=n;j++){
            ans = (1LL*ans*c[i][arr[j]])%mod;
        }
        dp[i]=ans%mod;
        for(int g=1;g<=i-1;g++){
            dp[i]-=((1LL*dp[i-g]*c[i][g])%mod);
        }
        dp[i]%=mod;
        if(dp[i]<0) dp[i]+=mod;
    }
    cout<<dp[m]<<endl;
    }
}

/* 
7 
3 3 
1 1 1
2 3
2 1 
2 3 
1 1 
3 3
1 1 2
3 3
1 2 2
3 3
2 2 2
3 3
3 3 3
 */