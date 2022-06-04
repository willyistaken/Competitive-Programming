#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double const pi = 3.14159265358979323846;
int main(){
    int n;scanf("%d",&n);
    pair<double,double> arr[n];
    double sumx=0;
    double sumx2=0;
    double sumy=0;
    double sumy2=0;
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&arr[i].first,&arr[i].second);
        sumx+=arr[i].first;
        sumx2+=arr[i].first*arr[i].first;
        sumy+=arr[i].second;
        sumy2+=arr[i].second*arr[i].second;
    }
    double ans=(n*sumx2) - (2*(sumx)*(sumx))+ (n*sumx2);
       ans+=(n*sumy2) - (2*(sumy)*(sumy))+ (n*sumy2);
    printf("%.9lf\n",(pi*ans/4)); 




    return 0;
}