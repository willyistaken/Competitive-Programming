#include <bits/stdc++.h>
using namespace std;
long long temp[7]={0,1,2,4,7,12,20};
map<long long,long long> already;
long long ans(long long n){
 if(n<=6){
     return temp[n];
 }
 if(!already.empty()){
     if(already.find(n)!=already.end()){
     return already[n];
 }
 }
 

    if(n%2==0){
        long long m = n/2;
        long long mi1 = ans(m-1);
        long long mi2=ans(m-2);
        long long sum=((mi1+1)*(mi2+1))%998244353;
        sum*=2;
        sum%=998244353;
        //sum+= ((mi2+1)*(mi2+1));
        sum%=998244353;
        sum+=((mi1+1)*(mi1+1))-1;
        sum%=998244353;
        already.insert(pair<long long,long long>(n,sum));
        return sum;
    }else{
        long long w = (n-1)/2;
        long long m = w+1;
        long long mmi1 = ans(m-1);
        long long mmi2= ans(m-2);
        long long wmi1 = ans(w-1);
        long long wmi2 = ans(w-2);
        long long sum=0;
        sum+=((mmi1+1)*(wmi2+1));
        sum%=998244353;
        //sum+=(mmi2+1)*(wmi2+1);
         sum%=998244353;
         sum+=((mmi2+1)*(wmi1+1));
          sum%=998244353;
          sum+=((wmi1+1)*(mmi1+1))-1;
           sum%=998244353;
           already.insert(pair<long long,long long>(n,sum));
           return sum;
    }



}


int main(){
    cin.tie(0);ios_base::sync_with_stdio(false);
    int t;cin>>t;
    for(int i=0;i<t;i++){
          long long n;cin>>n;
        cout<<ans(n)<<endl;
    }
      
   
}