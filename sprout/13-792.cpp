#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct vec{
    ll x;
    ll y;

};

long long operator^(const vec &x,const vec &y){
    return x.x*y.y-x.y*y.x;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    while(cin>>n){
    vec arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    arr[n]=arr[0];
    ll area=0;
    for(int i=0;i<n;i++){
        area+= arr[i]^arr[i+1];
    }
    area = abs(area);
    ll outline_length=0;
    for(int i=0;i<n;i++){
       if(arr[i].x==arr[i+1].x){
          outline_length+=abs(arr[i+1].y-arr[i].y); 
       } 
       if(arr[i].y==arr[i+1].y){
          outline_length+=abs(arr[i+1].x-arr[i].x); 
       } 
    }
    if(outline_length%2){
        cout<<area-(outline_length/2)-1<<".5\n";
    }else{
        cout<<area-(outline_length/2)<<".0\n";

    }
    }
    return 0;
}