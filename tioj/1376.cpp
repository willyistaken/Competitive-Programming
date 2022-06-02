#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<20> vis;
bool dfs(int n,vector<vector<int> > &sides,vector<int> &match){
    if(vis[n]) return false;
    vis[n]=1;
    for(auto i : sides[n]){
        if(match[i]<0 || dfs(match[i],sides,match)){
            match[i]=n;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    vector<int> match(n,-1);
    vector<vector<int> > sides(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b; 
        sides[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        vis.reset();
        dfs(i,sides,match);
    }
    int ans=0;
   for(int i=0;i<n;i++) {
       if(match[i]>=0) ans+=1;
   }
    cout<<ans<<endl;




    return 0;
}