//LDCS
//dp[i][j] consider the first array up to i_th element and need to use the j_th element of the second array
//dp[i][j] = dp[i-1][j] (if a[i]!=b[j])
//         = max(dp[i-1][k])+1 where 1<=k<j and b[k]>=b[j] (a[i]==b[j])
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n;cin>>n;
    int a[n+1],b[n+1];
    int dp[n+1][n+1] ={{0}};
    int path[n+1][n+1];
    for(int i=0;i<n;i++){
        cin>>a[i+1];
    }
    for(int i=0;i<n;i++){
        cin>>b[i+1];
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                path[i][j]=-1;
                continue;
            }
            if(a[i]!=b[j]){
                dp[i][j]=dp[i-1][j];
                path[i][j]=j;
            }else{
                int maxn=0;
                int maxid=-1;
                for(int g=j-1;g>=1;g--){
                    if(b[g]>=b[j]){
                        if(maxn<dp[i-1][g]){
                            maxn=dp[i-1][g];
                            maxid=g;                          
                        }
                    }
                }
                dp[i][j]=maxn+1;
                path[i][j]=maxid;
            }
            //cout<<path[i][j]<<" ";
        }
        //cout<<endl;
    }
    int maxnn=0;
    int indn=-1;
    for(int i=0;i<=n;i++){
        if(maxnn<dp[n][i]){
            maxnn=dp[n][i];
            indn=i;
        }
   } 
    stack<int> ans;
    for(int i=n;i>0;i--){
        if(indn==-1) break;
        if((path[i][indn]<indn && dp[i][indn]-dp[i-1][path[i][indn]]==1) || path[i][indn]==-1)  ans.push(b[indn]);
        indn=path[i][indn];
    }
    if(ans.empty()) cout<<endl;//note to myself: this line is the freaking reason it doesn't ac, because it needed endl even if the length of LCDS is 0. :(
    while(!ans.empty()){
        cout<<ans.top()<<" \n"[ans.size()==1];
        ans.pop();
    }
    }
    return 0;
}
