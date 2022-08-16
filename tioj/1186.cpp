#pragma GCC optimize("Ofast")
#include <cstdio>
int abs(int k){
    if(k<0) k = -k;
    return k;
}
using namespace std;
typedef long long ll;
int main(){
    int n;
    while(scanf("%d",&n) && n){
        int s = 2*n-1;
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(j==(n-1) || abs(j-(n-1))==abs(i-(n-1)) || i==n-1) putchar('*');
                else putchar(' ');
            }
            puts("");
        }
    }







    return 0;
}