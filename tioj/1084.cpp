#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<1100> vis;
const int N=505;
vector<pair<int,int> > side[N];
stack<int> ans;
int de[N];

void dfs(int r){ 
    for(auto i : side[r]){
        if(!vis[i.second]){
            vis[i.second]=1;
            dfs(i.first); 
        }
    }
    ans.push(r);
}




int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    while(cin>>m && m){
        vis.reset();
        for(int i=0;i<N;i++) {side[i].clear();de[i]=0;}
        int start=INT_MAX;
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            start = min({start,a,b});
            side[a].push_back({b,i});
            side[b].push_back({a,i});
            de[a]+=1;de[b]+=1;
        } 
        
        for(int i=504;i>=0;i--){
            if(de[i]%2) start = i;
            sort(side[i].begin(),side[i].end());
        }
        dfs(start);
        while(!ans.empty()){
            cout<<ans.top()<<"\n";
            ans.pop();
        }
        cout<<"\n";
    }






    return 0;
}