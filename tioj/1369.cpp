#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int r,vector<vector<int> > &side,int seq[],int &from){
    seq[r]=from++;
    for(auto i : side[r]){
        if(!seq[i]){
            dfs(i,side,seq,from);
        }
    } 
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<vector<int> > side(n+1);
    int seq[n+1]={0};
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        while(t--){
            int k;cin>>k;
            side[i].push_back(k);
        }
    }
    int it=1;
    dfs(1,side,seq,it);
    for(int i=1;i<=n;i++) cout<<seq[i]<<"\n";





    return 0;
}