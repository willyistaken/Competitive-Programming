#include <iostream>

using namespace std;
long long f[81]={0};
long long ans(long long n){
    if(f[n]){
        return f[n];
    }
    f[n]=ans(n-1)+ans(n-2);
    return f[n];
}
int main(){
    f[1]=1;
    f[2]=2;
    long long m;
    while(cin>>m && m){
        cout<<ans(m)<<endl;
    }
} 