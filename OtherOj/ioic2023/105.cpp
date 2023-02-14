#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int n,m; cin>>n>>m;
  int i,c,s;
  bool flag;
  vector<vector<pair<int,int>>> G(n);
  vector<int> d(n),v(n),u(m),ans;
  for(i=0;i<m;i++){
    int x,y; cin>>x>>y; --x; --y;
    G[x].push_back({y,i});
    G[y].push_back({x,i});
    d[x]++; d[y]++;
  }
  c=0; s=0;
  for(i=0;i<n;i++){
    if(d[i]&1) s=i,c++;
  }
  if(c!=0&&c!=2){
    cout<<"No\n";
    return 0;
  }
  function<void(int)> dfs=[&](int x){
    int i;
    v[x]=1;
    for(i=0;i<(int)G[x].size();){
      pair<int,int> cur=G[x][i++];
      if(!u[cur.second]){
        u[cur.second]=1;
        dfs(cur.first);
        ans.push_back(cur.second);
      }
    }
  };
  dfs(s);
  flag=1;
  for(i=0;i<n;i++){
    if(!v[i]){
      flag=0;
      break;
    }
  }
  if((int)ans.size()!=m||!flag){
    cout<<"No\n";
    return 0;
  }
  reverse(ans.begin(),ans.end());
  cout<<"Yes\n";
  cout<<s+1<<"\n";
  for(i=0;i<m;i++)
    cout<<ans[i]+1<<" \n"[i+1==m];
  return 0;
}
