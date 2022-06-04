#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cor{
    ll x;
    ll y;
};

unordered_map<ll,ll> k;

ll dis(cor x,cor y){
    return ((x.x-y.x)*(x.x-y.x))+((x.y-y.y)*(x.y-y.y));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    cor arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            k[dis(arr[i],arr[j])]+=1;
        }
    }
    ll sum=0;
    for(auto i : k){
        sum+= (i.second*i.second-i.second)/2;
    }
    cout<<sum<<endl;




    return 0;
}