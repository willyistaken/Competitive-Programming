#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// a naive gready doesn't work ex: in the case of 1-2-3-4-5
//new gready https://cs.stackexchange.com/questions/12177/correctness-proof-of-a-greedy-algorithm-for-minimum-vertex-cover-of-a-tree
bitset<100050> vis;
bitset<10050> select[n]={0};
void dfs(int from,int a,vector<vector<int> > &sides,int* dp){
    if(dp[a]) return dp[a];
    vis[a]=1;
    int minifinsum=1;
    for(auto i : sides[a]){
        for(auto j:sides[i]){
            minifinsum+=dfs(i,j,sides,dp);
        }
    }
    int minifnotsum=len(sides[a]-(a!=0));
    for(auto i :sides[a])
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<vector<int> > sides(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b; 
        a-=1;b-=1;
        sides[a].push_back(b);
        sides[b].push_back(a);
    }
   

}