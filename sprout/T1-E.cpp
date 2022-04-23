#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int> > side(n+1) ;
    vector<pair<int,int>> donumber(n+1,make_pair(0,0));
    for(int i=0;i<m;i++){
        int v,w;cin>>v>>w;
        side[v].push_back(w);
        side[w].push_back(v);
        donumber[v].first+=1;
        donumber[v].second=v;
        donumber[w].first+=1;
        donumber[w].second=w;
    }
    sort(donumber.begin(),donumber.end(),greater<pair<int,int> >());   
    vector<int> ans(n+1,0);
    vector<bool> already(n+1,0);
    queue<pair<int,int>> bfs;
    bfs.push(make_pair(donumber.front().second,0));
    already[donumber.front().second]=1;
    while(!bfs.empty()){
        pair<int,int> cur = bfs.front();
        bfs.pop();
        ans[cur.first] = cur.second;
        
        for(auto i : side[cur.first]){
            if(!already[i]){
                bfs.push(make_pair(i,cur.second+1));
                already[i]=1;
            }
        }
    }
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        cout<<ans[a]+ans[b]<<endl;
    }
    
}s