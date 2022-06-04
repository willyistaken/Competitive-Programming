#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct vec{
    ll x;
    ll y;
};
vec operator-(const vec a,const vec b){
    return {a.x-b.x,a.y-b.y};
}
ll operator*(const vec& a,const vec& b){
    return (1LL*a.x*b.x)+(1LL*a.y*b.y);
}
ll operator^(const vec& a,const vec& b){
    return (1LL*a.x*b.y)-(1LL*a.y*b.x);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    ll back=0;
    ll right=0;
    ll left=0;
    vec arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i].x>>arr[i].y;
    }
    vec prev = arr[1]-arr[0];
    for(int i=2;i<n;i++){
        if((prev*(arr[i]-arr[i-1]))<0 && (prev^(arr[i]-arr[i-1]))==0) ++back;
        if((prev^(arr[i]-arr[i-1]))>0) ++left;
        if((prev^(arr[i]-arr[i-1]))<0) ++right;
        prev = arr[i]-arr[i-1];
    }
    cout<<left<<" "<<right<<" "<<back<<"\n";
    return 0;
}