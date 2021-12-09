#include <bits/stdc++.h>
using namespace std;
int quantity[105];
int ans(int n,int m){
    if(n==m){
        return 1;
    }
    if(n>m){
        return 0;
    }
    int k=0;
    for(int j=1;j<=quantity[n];j++){
        k+=ans(n-1,m-j);
    }
    return k;
}
int main(){
    int n,m;cin>>n>>m;
    cout<<n<<" "<<m;
    return 0;
    for(int i=0;i<n;i++){
        cin>>quantity[i+1];
    }
    //cout<<ans(n,m)<<endl;
}