#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans[45]={0};
    ans[0]=1;
    ans[1]=1;
    ans[2]=5;
    for(int i=3;i<=44;i++){
        ans[i]=(ans[i-2]*4)+ans[i-1]+(ans[i-3]*2);
    }
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<ans[n]<<endl;
    }
}