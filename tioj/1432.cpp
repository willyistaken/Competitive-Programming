//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,w;
bool possible(ll v,vector<int> &arr){
    int stops=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>v) return 0;
        sum+=arr[i];
        if(sum>v){
            stops+=1;
            sum=arr[i];
        }
    }
    return stops<=w;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

   while(cin>>n>>w && (n||w)){
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    ll l=0;ll r=1e8;
    while(r-l>1){
        ll mid = (l+r)>>1;
        if(possible(mid,arr)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r<<endl;
   }




    return 0;
}