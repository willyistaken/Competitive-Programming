#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> father;
int query(int i){
    if(father[i]==i) return i;
    father[i] = query(father[i]);
    return father[i];
}

void join(int a,int b){
    father[query(a)] = query(b);
    return ;
}

bool check(int x,int y,int type){
    if(type==1){
        return !(query(3*x)==query(3*y+1) || query(3*x)==query(3*y+2));
    }else{
        return !(query(3*x)==query(3*y) || query(3*x)==query(3*y+2));
    }
}
void uni(int x, int y,int type){
    if(query(3*x)==query(3*y)) return ;
    if(type==1){
        join(3*x,3*y);
        join(3*x+1,3*y+1);
        join(3*x+2,3*y+2);
    }else{
        join(3*x,3*y+1);
        join(3*x+1,3*y+2);
        join(3*x+2,3*y);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    n+=5;int m;cin>>m;
    father.resize(3*n);
    for(int i=0;i<3*n;i++) father[i]=i;
    int ans=0;
    n-=5;
    for(;m;m--){
        int type;cin>>type;
        int a,b;cin>>a>>b;
        if(type==2 && a==b){ans++;continue;}
        if(a>n || b>n ){ans++;continue;}
        if(check(a,b,type)) uni(a,b,type);
        else ans++;
    }
    cout<<ans<<"\n";
    return 0;
}