#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;cin>>n;
    long double ans=(n>>1);
    for(int k=0;k<=1e8;k++){
        ans= (ans/2)+(n/(2*ans));
    }
    int first_d = (int)(log10(n)/2);
    cout.precision(51+first_d);
    cout<<ans;
    cout.precision(52+first_d);
    cout<<endl<<ans;
}