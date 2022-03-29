#include <bits/stdc++.h>
using namespace std;
int n;
struct qu_fu{
    double a;
    double b;
    double c;
    double eval(double t){
        return (a*(t-b)*(t-b))+c;
    }
};
double f(double t, vector<qu_fu> &arr){
    double maxd = arr[0].eval(t);
    for(int i=1;i<n;i++){
        maxd = max(maxd, arr[i].eval(t));
    }
    return maxd;
}
int main(){
    int t;cin>>t;
    while(t--){

    cin>>n;
    vector<qu_fu> arr(n);
    for(int i=0;i<n;i++){
        double ta,tb,tc;cin>>ta>>tb>>tc;
        qu_fu temp;
        temp.a =ta;temp.b = tb; temp.c = tc;
        arr[i]=temp;
    }

    double l=0.0,ml=5.0,mr=10.0,r=300.0;
    const int iter=1e6;
    for(int i=0;i<iter;i++){
         mr = (l + r) / 2.0;
         ml = (l + mr) / 2.0;
        if (f(ml,arr) < f(mr,arr)) r = mr;
         else l = ml;
    }
    cout<<fixed<<f((ml+mr)/2.0,arr)<<endl;
    }

}