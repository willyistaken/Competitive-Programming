#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct matrix{
    int n;
   long long arr[2][2]={{0}};
    void init(){
        arr[0][1]=1;
        arr[1][0]=1;
    }
    void print(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl; 
        }
        cout<<endl;
    }
};
const int MOD = 1e9+7;
matrix operator*(matrix a,matrix b){
    matrix temp;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                temp.arr[i][j]+=(1LL*a.arr[i][k]*b.arr[k][j])%MOD;
                temp.arr[i][j]%=MOD; 
            }
            temp.arr[i][j]%=MOD;
        }
    }
    return temp;
}
matrix power(matrix &a,ll n){
   matrix r;
   r.init();
   while(n){
       if(n&1) r = r*a;
       a = a*a;
       n>>=1;
   }
   return r;
}


ll nfib(ll n){
    n-=1;
    if(n<0) return 1;
    matrix fib;
    fib.arr[0][0]=1; fib.arr[0][1]=1; fib.arr[1][0]=1; fib.arr[1][1]=0;
    fib = power(fib,n);
    return ((1LL*fib.arr[1][0])+(1LL*fib.arr[1][1]))%MOD;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b;cin>>a>>b;
    ll k = __gcd(a+1,b+1);
    cout<<nfib(k-1)<<"\n";
    return 0;
}