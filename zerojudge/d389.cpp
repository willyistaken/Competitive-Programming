#include <bits/stdc++.h>
using namespace std;
int ans[77][2]={{0,0}};
int main(){
    int n;
    ans[0][0]=1;
    ans[0][1]=1;
    ans[1][0]=2;
    ans[1][1]=1;
    for(int i=2;i<=76;i++){
        ans[i][0]=ans[i-2][0]+ans[i-1][1];
        ans[i][1]=ans[i-2][0];
    }
    while(cin>>n){
        cout<<ans[n-1][0]<<endl;
    }
}