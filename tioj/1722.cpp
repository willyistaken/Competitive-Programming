#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e4+7;

struct matrix{
    int arr[2][2];
    void init(int v){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                arr[i][j]=0;
                if(i==j) arr[i][j]=v;
            }
        }
    }
    void print(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cerr<<arr[i][j]<<" ";
            }
            cerr<<"\n";
        }
    }
};

matrix operator*(matrix a,matrix b){
    matrix r;
    r.init(0);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                r.arr[i][j]+=(a.arr[i][k]*b.arr[k][j])%MOD;
                r.arr[i][j]%=MOD;
            }
        }
    }
    return r;
}

int getf(int n){
    n--;
    matrix g;
    g.init(1);
    matrix fib;
    fib.arr[0][0]=0;fib.arr[0][1]=1;fib.arr[1][0]=1;fib.arr[1][1]=1;
    while(n){
        if(n&1) g = g*fib;
        fib = fib*fib;
        n>>=1;
    }
    int ans=g.arr[0][0]+g.arr[1][0];
    ans%=MOD;
    return ans;

}

int inv(int n){
    int  p =1e4+5;
    int r=1;
    while(p){
        if(p&1) r=(r*n)%MOD;
        n = (n*n)%MOD;
        p>>=1;
    }
    return r;
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
       int a,b;cin>>a>>b;
       a++;b++;
        int fa = getf(a);
        int fb = getf(b);
        int fgcd = getf(__gcd(a,b));
        int invf = inv(fgcd);
        cout<<(2LL*fa*fb*invf)%MOD<<"\n";
    }







    return 0;
}