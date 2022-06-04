#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-10;
bool eq(double a,double b){
    if(b>a) swap(a,b);
    if((a-b)<=eps && (b-a)>=-eps) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    double arr[n];
    int ans=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans+=eq(arr[i]+arr[j],arr[k]);
            }
        }
    }
    cout<<ans<<endl;






    return 0;
}