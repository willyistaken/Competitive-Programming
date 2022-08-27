#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct query{
    int l;
    int r;
    int t;
    int ans;
};
int n,Q;
struct fenwick{
    vector<int> arr;
    void init(){
        arr.resize(n+1);
        fill(arr.begin(),arr.end(),0);
    }
    void add(int id,int v){
        while(id<=n){
            arr[id]+=v;
            id+=(id & -id);
        }
    }
    int query(int id,bool dir){
        int result=0;
        while(id){
            result+=arr[id];
            id-=(id & -id);
        }
        if(dir) result = query(n,0)-result; 
        return result;
    }
} bit;
int ans;
int l0,r0;
vector<int> arr;

void add(int id,bool dir){
    if(dir){
        ans+=bit.query(arr[id],0);
        bit.add(arr[id],1);
    }else{
        ans+=bit.query(arr[id],1);
        bit.add(arr[id],1);
    }
}

void remove(int id,bool dir){

    if(dir){
        bit.add(arr[id],-1);
        ans-=bit.query(arr[id],0);
    }else{
        bit.add(arr[id],-1);
        ans-=bit.query(arr[id],1);
    }
}

void go(int l,int r){
    while(r0<r) add(++r0,1);
    while(l0>l) add(--l0,0);
    while(r0>r) remove(r0--,1);
    while(l0<l) remove(l0++,0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>Q;
    bit.init();
    arr.resize(n+1);
    vector<int> d(n);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        d[i-1]=arr[i];
    }
    sort(d.begin(),d.end());
    d.resize(unique(d.begin(),d.end())-d.begin());
    for(int i=1;i<=n;i++){
        arr[i] = lower_bound(d.begin(),d.end(),arr[i])-d.begin()+1;
    }

    add(1,1),add(2,1);r0=2;l0=1;
    query a[Q];
    for(int i=0;i<Q;i++){
        cin>>a[i].l>>a[i].r;
        a[i].t=i;
    }
    int B = n/sqrt(Q);
    sort(a,a+Q,[&](const query &a,const query &b){return (((a.l/B)==(b.l/B))?(a.r<b.r):(a.l<b.l));});
    for(int i=0;i<Q;i++){
        if(a[i].l==a[i].r) {
            a[i].ans=0;
            continue;
        }
        go(a[i].l,a[i].r);
        a[i].ans = (1LL*(a[i].r-a[i].l)*(a[i].r-a[i].l+1))/2 - ans;
    }
    sort(a,a+Q,[](const query &a,const query &b){return a.t<b.t;});
    for(int i=0;i<Q;i++) cout<<a[i].ans<<"\n";


    return 0;
}
