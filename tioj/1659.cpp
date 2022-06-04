#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool notprime[5001];
int main(){
    notprime[1]=1;
    notprime[0]=0;
    for(int i=2;i<=5000;i++){
        if(!notprime[i]){
            for(int j=2;j*i<=5000;j++){
                notprime[j*i]=1;
            }
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("primes between 1 ~ %d:",n);
        for(int i=1;i<=n;i++){
            if(!notprime[i]){
                printf(" %d",i);
            }
        }
        puts("");
    }





    return 0;
}