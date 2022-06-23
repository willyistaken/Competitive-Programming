#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
bool dfs(int r,vector<vector<int> > &side,vector<int> &match,vector<bool> &vis){
    for(auto i:side[r]){
        if(!vis[i]){
            vis[i]=1;
            if(match[i]==-1 || dfs(match[i],side,match,vis)){
                match[i]=r;
                return true;
            }
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    while(cin>>n>>k && (n||k)){
        vector<int> match(n,-1);
        vector<vector<int> > side(n);
        for(int i=0;i<k;i++){
            int a,b;cin>>a>>b;
            a-=1;b-=1;
            side[a].push_back(b);
        }
        for(int i=0;i<n;i++){
            vector<bool> vis(n,0);
            dfs(i,side,match,vis);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(match[i]>=0) ans++;
        }
        cout<<"Case #"<<t<<":"<<ans<<endl;
        t++;
    }







    return 0;
}