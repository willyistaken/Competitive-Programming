#include <bits/stdc++.h>
using namespace std;
long long ans[100005]={0};
int main(){
    int mod = 1000007;
    ans[0]=1;
    ans[1]=0;
    ans[2]=3;
    int t;cin>>t;
    int alreadydone = 2;
    long long sum=4;//ans[2]+ans[0] (ans[0] is 1)
    while(t--){
      int n;cin>>n;
    if(n<=alreadydone){
        cout<<ans[n]<<endl;
    }else{
         for(int i=alreadydone+1;i<=n;i++){
        if(i%2==1){
            ans[i]=0;
            continue;
        }  
        ans[i]=(1LL*ans[i-2]%mod)+((2LL*sum)%mod);
        ans[i]%=mod;
        sum+=ans[i]%mod;
        sum%=mod;
    }
    alreadydone = n;  
    cout<<ans[n]<<endl;  
    }

 
    }
    
}