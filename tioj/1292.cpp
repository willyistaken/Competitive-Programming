#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// a naive gready doesn't work ex: in the case of 1-2-3-4-5
//new gready https://cs.stackexchange.com/questions/12177/correctness-proof-of-a-greedy-algorithm-for-minimum-vertex-cover-of-a-tree
bitset<100050> vis;
bitset<10050> cover;
int ans=0;
void dfs(int a,vector<vector<int> > &sides,vector<int> &father,vector<int> &deptharr,int depth){
    if(vis[a]) return;
    vis[a]=1;
    deptharr[a]=depth;
    for(auto i: sides[a]) {
        if(!vis[i]) {
            father[i]=a;
            dfs(i,sides,father,deptharr,depth+1);
        } 
    }
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
    vector<int> father(n);
    father[0]=-1;
    vector<int> depth(n);
    vis.reset();
    dfs(0,sides,father,depth,1);
    vector<pair<int,int> > order;
    for(int i=0;i<n;i++){
        order.push_back(make_pair(depth[i],i));
    }
    sort(order.begin(),order.end(),greater<pair<int,int> >() ); 
    set<int> selected;
    for(int i=0;i<n-1;i++){
        if(!cover[order[i].second]){
            selected.insert(father[order[i].second]);
            cover[order[i].second]=1;
            cover[father[order[i].second]]=1;
        }
    }
    if(!cover[0] && n!=1) ans+=1;
    cout<<selected.size()<<endl;

}