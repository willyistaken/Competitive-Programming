#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    int from;
    int to;
    int w;
};
int query(int p,int father[]){
    if(father[p]==p) return p;
    father[p] = query(father[p],father);
    return father[p];
}

void join(int a,int b,int father[]){
    father[query(a,father)] = query(b,father);
    return ;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int m;cin>>m;
    int k;cin>>k;
    vector<edge> s;
    for(int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        s.push_back({a,b,w});
    }
    int father[n+1]={0};
    sort(s.begin(),s.end(),[](const edge &a,const edge &b){return a.w<b.w;});
    int minST=0;
    for(int i=1;i<=n;i++) father[i]=i;
    for(auto e: s){
        if(query(e.to,father)!=query(e.from,father)){
            minST += e.w;
            join(e.to,e.from,father);
        }
    }
    sort(s.begin(),s.end(),[](const edge &a,const edge &b){return a.w>b.w;});
    int maxST=0;
    for(int i=1;i<=n;i++) father[i]=i;
    for(auto e: s){
        if(query(e.to,father)!=query(e.from,father)){
            maxST += e.w;
            join(e.to,e.from,father);
        }
    }
    if(k>=minST && k<=maxST){
        puts("TAK");
    }else{
        puts("NIE");
    }


    return 0;
}