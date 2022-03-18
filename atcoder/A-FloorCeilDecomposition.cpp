#include <bits/stdc++.h>
using namespace std;
map<long long,long long> mp;
long long ans(long long n){
    if(mp.count(n)!=0){
        return mp[n];
    }
    if(n<=3){
        mp[n]=n;
        return n;
    }else{
        if(n%2){
            mp[n]= (ans(n/2)*ans((n+1)/2))%998244353;
            return mp[n];
        }else{
            long long a=ans(n/2);
            mp[n]= (a*a)%998244353;
            return mp[n];
        }
    }
}
int main(){
    long long n;cin>>n;
    cout<<ans(n)<<endl;
}