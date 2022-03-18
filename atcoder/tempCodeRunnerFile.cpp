#include <bits/stdc++.h>
using namespace std;
long long ans(long long n){
    if(n<=3){
        return n;
    }else{
        if(n%2){
            return (ans(n/2)*ans((n+1)/2))%998244353;
        }else{
            long long a=ans(n/2);
            return (a*a)%998244353;
        }
    }
}
int main(){
    int n;cin>>n;
    cout<<ans(n)<<endl;
}