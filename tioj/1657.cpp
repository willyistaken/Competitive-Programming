#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d*%d=%d",i,j,i*j);
            putchar((j==m)? '\n':' ');
        }
    }
    }







    return 0;
}