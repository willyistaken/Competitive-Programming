#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
    int v;
    int t;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int s,e;cin>>s>>e;
    int from[n+1]={0};
    vector<vector<int> > sides(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b; 
        sides[a].push_back(b);
        sides[b].push_back(a);
    }
    priority_queue<st,vector<st>,function<bool(st,st)> > bfs([](const st &a,const st&b){return (a.t>b.t||(a.t==b.t && a.v>b.v));});
    from[e]=-1;
    bfs.push({e,0});
    while(!bfs.empty()){
        st cur = bfs.top();
        bfs.pop();
        if(cur.v==s){
            queue<int> ans;
            cout<<cur.t-1<<endl;
            int now=cur.v;
            while(now!=-1){
                ans.push(now);
                now = from[now];
            }
            while(!ans.empty()){
                cout<<ans.front()<<"-\n"[ans.size()==1];
                ans.pop();
            }
            return 0;
        }
        for(auto i : sides[cur.v]){
            if(from[i]==0){
                from[i]=cur.v;
                bfs.push({i,cur.t+1});
            }
        }
    }
    return 0;
}

//debug 的酷題目，沒有坑人只是邏輯要很清楚
