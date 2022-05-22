#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void white(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(abs((j-n+1))==i || i==n-1){
                putchar('*');
            }else{
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

inline void black(int n){
        for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            if(abs((j-n+1))<=i || i==n-1){
                putchar('*');
            }else{
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main(){

    int n;int type;
    while(scanf(" %d %d",&n,&type)!=EOF){
        if(type){
            black(n);
        }else{
            white(n);
        }
    }
    return 0;
}