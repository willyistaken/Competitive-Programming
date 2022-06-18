#include <cstdio>

void buildWall(int, int, int[], int[], int[], int[], int[]);

namespace Wall{
    const int N = 5e5+1, M = 2e6+1;
    int n,k,op[N],left[N],right[N],hight[N],finalHight[M];
    void init(){
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;i++){
            scanf("%d%d%d%d",op+i,left+i,right+i,hight+i);
        }
    }
    void solve(){
        buildWall(n,k,op,left,right,hight,finalHight);
        for(int i=0;i<n;i++){
            printf("%d ",finalHight[i]);
        }
    }
}

int main()
{
    Wall::init();
    Wall::solve();
    return 0;
}