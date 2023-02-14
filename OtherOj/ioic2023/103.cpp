#include<bits/stdc++.h>
#define ll long long
#define inf (1ll<<50)
#define node int
#define home 0
#define live 1
#define cool double
#define edge pair<node,cool>
#define to first
#define c second
#define pressure double
#define damage ll
#define elem pair<pressure,node>
#define cp first
#define cn second

using namespace std;

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int n,m; cin>>n>>m;
  vector<vector<edge>> G(n),rG(n);
  for(int i=0;i<m;i++){
    int x; edge e;
    cin>>x>>e.to>>e.c;
    G[x].push_back(e);
    swap(x,e.to);
    rG[x].push_back(e);
  }
  damage ans=0;
  function<bool()> sp=[&](){
    vector<pressure> mp(n,inf);
    vector<bool> v(n);
    priority_queue<elem,vector<elem>,greater<elem>> pq;
    pq.push({mp[home]=0,home});
    while(!pq.empty()){
      int x=pq.top().cn; pq.pop();
      if(v[x]) continue;
      v[x]=1;
      for(const edge &e:G[x]){
        if(!v[e.to]&&mp[e.to]>mp[x]+e.c)
          pq.push({mp[e.to]=mp[x]+e.c,e.to});
      }
    }
    ans+=mp[live];
    return -v[live];
  };
  function<bool()> rsp=[&](){
    vector<pressure> mp(n,inf);
    vector<bool> v(n);
    priority_queue<elem,vector<elem>,greater<elem>> pq;
    pq.push({mp[home]=0,home});
    while(!pq.empty()){
      int x=pq.top().cn; pq.pop();
      if(v[x]) continue;
      v[x]=1;
      for(const edge &e:rG[x]){
        if(!v[e.to]&&mp[e.to]>mp[x]+e.c)
          pq.push({mp[e.to]=mp[x]+e.c,e.to});
      }
    }
    ans+=mp[live];
    return -v[live];
  };
  if(!sp()||!rsp()) ans=0;
  cout<<ans<<"\n";
  return 0;
}
