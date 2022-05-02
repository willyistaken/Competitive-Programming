#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int a){
    if(a==1) return 1;
    return 2*solve(a>>1);
}
int main(){
    int n;
    while(scanf("%d",&n) && n){
        ll ans=0;int a;
        ans+=solve(n);
        while(scanf("%d",&a) && a){
                ans+=solve(a);
        }
        printf("%lld\n",ans);   
    }
 
}