#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long arr[14];
    long long now=1;
    arr[0]=1;
    for(int i=1;i<=13;i++){
        arr[i]=now*i;
        now*=i;
    }
    int t;
    scanf("%d",&t);
    for(int f=1;f<=t;f++){
        int n;scanf("%d",&n);
        printf("Case #%d:\n",f);
        for(int i=0;i<=n;i++){
            printf("TFCIS%d=%lld\n",i,arr[i]);
        }
    }







    return 0;
}