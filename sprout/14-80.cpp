#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
void change(int ind,int v,vector<int> &seg){
    ind+=n;
    seg[ind]=v;
    ind>>=1;
    while(ind){
        seg[ind]=min(seg[ind*2],seg[ind*2+1]);
        ind>>=1;
    }
}
int query(int l,int r,vector<int> &seg){
    l+=n;r+=n;
    int ans=INT_MAX;
    while(l<r){
        if(l%2) ans=min(seg[l++],ans);
        if(r%2) ans=min(seg[--r],ans);
        r>>=1;l>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t>>n;
    vector<int> seg(2*n,0);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        change(i,a,seg);
    }
    for(;t;t--){
        int type;cin>>type;
        if(type==1){
            int l,r;cin>>l>>r;
            r+=1;
            cout<<query(l,r,seg)<<endl;
        }else{
            int ind,v;cin>>ind>>v;
            change(ind,v,seg);
        }
    }





    return 0;
}

/*
6 5
2 3 5 1 4
1 0 1
1 2 4
2 0 5
2 2 2
1 0 1
1 2 4
*/