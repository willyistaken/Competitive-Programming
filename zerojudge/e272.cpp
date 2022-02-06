#include <bits/stdc++.h>
using namespace std;
long long fib[10001]={0};
int gcd(int a,int b){
    return (a==0) ? b:gcd(b%a,a);
}
int main(){
    fib[1]=1;
    fib[2]=1;
    for(int i=3;i<=10000;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    int n,m;
    while(cin>>n>>m){
        cout<<fib[gcd(n,m)]<<endl;
    }

}