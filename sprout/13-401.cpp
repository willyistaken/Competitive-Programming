#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct vec{
    ll x;
    ll y;
};
int sign(ll a){
    if(a==0) return 0;
    return (a>0) ? 1:-1;
}
ll operator*(const vec& a,const vec& b){
    return a.x*b.x+a.y*b.y;
}
ll operator^(const vec& a,const vec& b){
    return a.x*b.y-a.y*b.x;
}
vec operator-(const vec& a,const vec& b){
    return {a.x-b.x,a.y-b.y};
}
int ori(const vec& a,const vec& b,const vec& o){
    return sign((a-o)^(b-o));
}
bool btw(const vec& p1,const vec& p2,const vec& t){
    if(ori(p1,p2,t)!=0) return 0;
    return ((t-p1)*(t-p2)<=0);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        vec p1,p2,q1,q2;
        cin>>p1.x>>p1.y>>p2.x>>p2.y>>q1.x>>q1.y>>q2.x>>q2.y;
        int o123 = ori(p1,p2,q1);
        int o124 = ori(p1,p2,q2);
        int o342 = ori(q1,q2,p2);
        int o341 = ori(q1,q2,p1);
        if(o123==0 && o124==0){
            if(btw(p1,p2,q1) || btw(p1,p2,q2) || btw(q1,q2,p1) || btw(q1,q2,p2)){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }else{
            if(o123*o124<=0 && o341*o342<=0){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }







    return 0;
}