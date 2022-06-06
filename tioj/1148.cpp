#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct vec{
    ll x;
    ll y;
};
ll operator^(const vec &a,const vec &b){
    return a.x*b.y - a.y*b.x;
}
vec operator-(const vec &a,const vec &b){
    return {a.x-b.x,a.y-b.y};
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vec arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
    }
    sort(arr,arr+n,[](const vec &a,const vec &b){return (a.x<b.x || (a.x==b.x && a.y<b.y));}) ;
    vector<int> convexhull;
        for(int i=0;i<n;i++){
            while(convexhull.size()>=2){
                if(((arr[convexhull[convexhull.size()-1]]-arr[convexhull[convexhull.size()-2]])^(arr[i]-arr[convexhull[convexhull.size()-1]]))>0){
                    break;
                }
                convexhull.pop_back();
            }
            convexhull.push_back(i);
        }
        convexhull.pop_back();
        int s = convexhull.size();
        for(int i=n-1;i>=0;i--){
            while(convexhull.size()-s>=2){
                if(((arr[convexhull[convexhull.size()-1]]-arr[convexhull[convexhull.size()-2]])^(arr[i]-arr[convexhull[convexhull.size()-1]]))>0){
                    break;
                }
                 convexhull.pop_back();
            }
            convexhull.push_back(i);
        }
    cout<<convexhull.size()-1<<endl;







    return 0;
}