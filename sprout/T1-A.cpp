#include <bits/stdc++.h>
using namespace std;

pair<int,int> ans[200010];
 int c[200010];
pair<int,int> dfsans(int root,vector<bool> &already,vector<int> &level,vector<vector<int> > &side){
    if(ans[root].first) return ans[root];
    already[root]=1;
    int maxn=c[root];
    int minn=c[root];
    for(auto i : side[root]){
        if(!already[i] && level[i]>level[root]){
            pair<int,int> temp = dfsans(i,already,level,side);
            maxn = max(maxn,temp.first);
            minn = min(minn,temp.second);
        }
    }
    ans[root]=make_pair(maxn,minn);
    return ans[root];
}
void init(int cur,vector<bool> &already,vector<int> &level,int k,vector<vector<int> > &side){
    level[cur] = k+1;
    already[cur]=1;
    bool leaf=1;
    for(auto i : side[cur]){
        if(!already[i]){
            leaf=0;
            init(i,already,level,k+1,side);
        }
    }
    if(leaf){
        ans[cur]=make_pair(c[cur],c[cur]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    vector<vector<int>> side(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        side[a].push_back(b);
        side[b].push_back(a);
    }
   
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    vector<int> level(n+1);
    vector<bool> already(n+1,0);
    init(1,already,level,0,side);    
    for(int i=0;i<q;i++){
        vector<bool> already2(n+1,0);
        int r;cin>>r;
        pair<int,int> temp = dfsans(r,already2,level,side);
        cout<<temp.first-temp.second<<endl;
    }



}