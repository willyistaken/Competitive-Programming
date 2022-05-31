#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    double avy=0;
    for(int i=0;i<n*n;i++){
        double r,g,b; 
        scanf("%lf %lf %lf",&r,&g,&b);
        printf("%.4lf %.4lf %.4lf\n",0.5149 * r + 0.3244 * g + 0.1607 * b, 0.2654 * r + 0.6704 * g + 0.0642 * b,0.0248 * r + 0.1248 * g + 0.8504 * b);
        avy+=0.2654 * r + 0.6704 * g + 0.0642 * b;
    }
    printf("The average of Y is %.4lf",avy/=(n*n));







    return 0;
}