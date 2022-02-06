#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int t;cin>>t;
    int ans1[200005]={0};
    int ans2[200005]={0};
    ans1[1]=0;
    ans2[1]=1;
    for(int i=2;i<=200000;i++){
        ans1[i]=ans2[i-1]+ans1[i-1]%998244353;
        ans2[i]=(ans1[i-1]+1)%998244353;
    }
    for(int i=0;i<t;i++){
        int n;cin>>n;
        cout<<(ans2[n]+ans1[n])%998244353<<endl;
    }
}