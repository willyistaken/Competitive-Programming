#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int query(int a,vector<int> &father){
    if(father[a]==a) return father[a];
    father[a] = query(father[a],father);
    return father[a];
}
void join(int a,int b,vector<int> &father){
    father[query(a,father)] = query(b,father);
    return;
}
struct sides{
    int from;
    int to;
    int w;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vector<int> father(n);
    for(int i=0;i<n;i++) father[i]=i;
    sides arr[m];
    for(int i=0;i<m;i++){
        sides t;
        cin>>t.from>>t.to>>t.w;
        t.from--;
        t.to--;
        arr[i]=t;
    }
    sort(arr,arr+m,[](const sides &a,const sides &b){return a.w<b.w;});
    ll ans=0;
    for(int i=0;i<m;i++){
        if(query(arr[i].from,father)!=query(arr[i].to,father)){
            ans+=arr[i].w;
            join(arr[i].from,arr[i].to,father);
        }
    }
    cout<<ans<<endl;

    return 0;
}