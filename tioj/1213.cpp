#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(int root,vector<vector<pair<int,int> > > &sides,vector<bool> &visited,pair<int,int>* maxn,int curlengh){
    visited[root]=1;
    for(auto i : sides[root]){
        if(visited[i.first]==0){
            dfs(i.first,sides,visited,maxn,curlengh+i.second);
        }
    }
    if(maxn->second<curlengh){
            maxn->first=root;
            maxn->second=curlengh;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n && n){
    vector<vector<pair<int,int> > > sides(n);
    for(int i=0;i<n-1;i++){
        int a,b,w;cin>>a>>b>>w;
        a-=1;
        b-=1;
        sides[a].push_back({b,w});
        sides[b].push_back({a,w});
    }
    vector<bool> visited(n);
    fill(visited.begin(),visited.end(),0);
    pair<int,int> maxn={0,0};
    dfs(0,sides,visited,&maxn,0); 
    fill(visited.begin(),visited.end(),0);
    dfs(maxn.first,sides,visited,&maxn,0);
    cout<<maxn.second<<endl;
    }




    return 0;
}