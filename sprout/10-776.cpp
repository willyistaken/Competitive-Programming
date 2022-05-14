#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N,M,L;
int const mod = 1000000007;
struct matrix{
    vector<vector<ll> > a = vector<vector<ll> >(N,vector<ll>(N,0));
    void print(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<a[i][j]<<" \n"[j==N-1];
            }
        }
    }

};   
matrix I(){
        matrix temp;
        for(int i=0;i<N;i++){
                temp.a[i][i]=1;
        }
        return temp;
    }
matrix operator*(matrix a,matrix b){
    matrix temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                temp.a[i][j]+=(1LL*a.a[i][k]*b.a[k][j])%mod;
                if(temp.a[i][j]>(1LL<<44)) temp.a[i][j]%=mod; 
            }
            temp.a[i][j]%=mod;
        }
    }
    return temp;
}

matrix power(matrix a,int n){
    if(n==0) return I();
    if(n==1) return a;
    matrix ret,now;
    ret=I(); 
    now=a;
    while(n){
        if(n&1) ret = ret*now;
        now = now*now;
        n>>=1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M>>L;
    matrix ans;
    for(int i=0;i<M;i++){
        int x,y;cin>>x>>y; 
        ans.a[x-1][y-1]+=1;
    }
    ans = power(ans,L);
    ans.print();
    return 0;
}