#include <bits/stdc++.h>
using namespace std;
bool dfs(int start,vector<vector<int>> &side,vector<int> &typeofp,int ty){
    typeofp[start]=ty;
    for(auto i : side[start]){
        if(typeofp[i]+1){
            if(typeofp[start]==typeofp[i]){
                return false;
            }
        }else{
            if(dfs(i,side,typeofp,!ty)==0){
        
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
       int n,m;cin>>n>>m;
    vector<vector<int> > side(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        side[a].push_back(b);
        side[b].push_back(a);
    }
    vector<int> typeofp(n,-1);

    string out="NORMAL.\n";
    for(int i=0;i<n;i++){
        if(typeofp[i]==-1){
            if(!dfs(i,side,typeofp,1)){
                out="RAINBOW.\n";
            }
        }
    }
    cout<<out;
     
    }
    
}