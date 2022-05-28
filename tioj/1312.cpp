#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int query(int k,int* boss){
    if(boss[k]==k){
       return k; 
    }
    boss[k] = query(boss[k],boss);
    return boss[k];
}
void join(int a,int b,int* boss){
    int first = query(a,boss);
    int second = query(b,boss);
    if(first<second){
        boss[second]=first;
    }else{
        boss[first]=second;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m){
    int boss[n+1]={0};
    for(int i=1;i<=n;i++) boss[i]=i;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b; 
        join(a,b,boss);
    }
    int k;cin>>k;
    cout<<query(k,boss)<<endl;
    }
    return 0;
}