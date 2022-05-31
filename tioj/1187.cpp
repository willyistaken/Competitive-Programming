#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    while(scanf("%d",&n) && n){
        double sum=0;
        double now;
        double maxn=-1;
        double minn=11;
        for(int i=0;i<n;i++){
            scanf("%lf",&now);
            sum+=now;
            minn=min(minn,now);
            maxn=max(maxn,now);
        }
        sum-=minn;
        sum-=maxn;
        printf("%.2lf\n",sum/(n-2));
    }







    return 0;
}