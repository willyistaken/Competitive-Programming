#pragma GCC optiminaze("O2")
#pragma GCC optiminaze("unroll-loops")
#pragma loop_opt(on)
#include <algorithm>
#include "lib1338.h"
using namespace std;
const int MAXN=1000005;const int MAXNP = 21;
long gcda[MAXNP][MAXN];
long mina[MAXNP][MAXN];
void init(int N,int long long c[]){
    for(int i=0;i<N;i++){
        gcda[0] [i]= mina[0][i] = c[i];
    }
    for(int i=1;i<MAXNP;i++){
        for(int j=0;j<N;j++){
                mina[i] [j]= min(mina[i-1][j],mina[i-1][j+(1<<i-1)]);
                gcda[i][j] = __gcd(gcda[i-1][j],gcda[i-1][j+(1<<i-1)]);
            }
        }
}

int query(int l,int r){
    int p = __lg(r-l);
    return __gcd(gcda[p][l],gcda[p][r-(1<<p)])==min(mina[p][l],mina[p][r-(1<<p)]);
} 
