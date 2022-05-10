#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
struct frac{
    double v;
    int top;
    int bottom;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<frac > arr;
    for(int i =n;i>0;i--){
        for(int j=1;j<i;j++){
           if(__gcd(i,j)==1){
               arr.push_back({(double)j/(double)i,j,i});
           }
        }
    }
    sort(arr.begin(),arr.end(),[](frac a,frac b){return a.v<b.v;});
    cout<<arr.size()<<endl;
    if(n==2){
    cout<<"1/2"<<endl;
    }else{
    cout<<arr[n-1].top<<"/"<<arr[n-1].bottom<<endl;
    }
    






    return 0;
}