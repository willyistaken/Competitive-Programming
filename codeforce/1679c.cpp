#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
void modify(int ind,int v,vector<int> &segtree){
    ind +=n;
    segtree[ind]+=v;
    while(ind>1){
       ind>>=1;
       segtree[ind]=(segtree[ind*2] && segtree[2*ind+1]); 
    }
}
bool query(int l,int r,vector<int> &segtree){
    l+=n;r+=n;
    if(r-l==1) return (segtree[l]!=0);
    bool ans=1;
    while(l<r){
        if(l%2){
            ans=(ans&&segtree[l++]);
        }
        if(r%2){
            ans = (ans&&segtree[--r]);
        }
        r>>=1;l>>=1;
        if(ans==false) return ans;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    string ans[2]={"NO\n","YES\n"};
    vector<int> x(2*n,0);
    vector<int> y(2*n,0);
    for(int i=0;i<q;i++){
        int type;cin>>type;
        if(type<=2){
            int a,b;cin>>a>>b;
            modify(a-1,-2*type+3,x);
            modify(b-1,-2*type+3,y);
        }else{
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            cout<<ans[(query(x1-1,x2,x) || query(y1-1,y2,y))];
        }
    }





    return 0;
}