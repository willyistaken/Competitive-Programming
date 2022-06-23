#pragma GCC optimize("Ofast")
#include <cstdio>
#include <bitset>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
bitset<10010> vis;
pair<int,int> dfs(int r,vector<vector<int> > &side){
    vis[r]=1;
    pair<int,int> maxn = {-1,r};
    for(auto i : side[r]){
        if(!vis[i]){
           maxn = max(maxn,dfs(i,side)); 
        }
    }
    maxn.first+=1;
    return maxn;
}

int main(){
    int n;scanf("%d",&n);
    vis.reset();
    vector<vector<int> > side(n);
    for(int i=0;i<n;i++){
        int k=0;
        while(scanf("%d",&k) && k>=0){
           side[i].push_back(k);
           side[k].push_back(i); 
        }
    }
    int next = dfs(0,side).second;
    vis.reset();
    printf("%d\n",dfs(next,side).first);
    return 0;
}