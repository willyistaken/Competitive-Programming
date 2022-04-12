#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &ans,int n){
    if(n==1){
        ans[0]=1;
        return;
    }
    if(n==2){
        ans[0]=1;
        ans[1]=2;
        return ;
    }
    if(n==3){
        ans[0]=1;
        ans[1]=3;
        ans[2]=2;
        return ;
    }
    int half = n/2;
    if(n%2) half++;
    vector<int> sub(half,0);
    solve(sub,half);
    for(int i=0;i<half;i++){
        ans[i] = (sub[i]*2)-1;
    }
    int i = half;
    int id=0;
    while(i<n){
        if(sub[id]*2<=n){
            ans[i] = sub[id]*2;
            i++;
        }
        id++;
    }
}
int main(){
    int n;cin>>n;
    vector<int> ans(n,0);
    solve(ans,n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i==n-1];
    }
}