#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1024;

struct seg{
    int arr[2*N]={0};
    void change(int ind,int v){
        ind+=N;
        arr[ind]=v;
        while(ind>0){
            ind>>=1;
            arr[ind]=max(arr[2*ind],arr[2*ind^1]);
        }
    }
    int query(int l,int r){
        l+=N;
        r+=N;
        int maxn=0;
        while(l<r){
            if(l%2) maxn=max(maxn,arr[l++]);
            if(r%2) maxn=max(maxn,arr[--r]);
            l>>=1;
            r>>=1;
        }
        return maxn;
    }
};
struct SEG{
    seg arr[2*N];
    void change(int x,int y,int v){
        y+=N;
        arr[y].change(x,v);
        while(y>0){
            y>>=1;
            arr[y].change(x,max(arr[y*2].arr[x+N],arr[2*y^1].arr[x+N]));
        }
    }
    int query(int lx,int rx,int ly,int ry){
        ly+=N;ry+=N;
        int maxn=0;
        while(ly<ry){
            if(ly%2) maxn=max(maxn,arr[ly++].query(lx,rx)); 
            if(ry%2) maxn=max(maxn,arr[--ry].query(lx,rx));
            ly>>=1;ry>>=1;
        }
        return maxn;
    }
};
struct cor{
    int x;
    int y;
    int v;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<cor> order;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;cin>>a;
            order.push_back({i,j,a});
        }
    }
    sort(order.begin(),order.end(),[](const cor &a,const cor &b){return a.v<b.v;});
    SEG g;
    int maxn=0;
    for(int i=0;i<n*n;i++){
        int ans=g.query(0,order[i].x+1,0,order[i].y+1);
        ans+=1;
        maxn=max(maxn,ans);
        g.change(order[i].x,order[i].y,ans);
    }
    cout<<maxn<<endl;


    return 0;
}