#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n,m,s,e,f;cin>>n>>m>>s>>e>>f;
    vector<vector<pair<int,ll> > > sides(n+1);
    for(int i=0;i<m;i++){
        int a,b,c,d,cp;cin>>a>>b>>c>>d>>cp;
        ll cost;
        if(d>=f){
            cost = 1LL*c*f;
        }else{
            cost = (1LL*d*c)+(1LL*(f-d)*cp);
        }
        sides[a].push_back({b,cost});
    }
    ll dis[n+1];
    fill(dis,dis+n+1,1e16);
    dis[s]=0;
    queue<int> uq;
    uq.push(s);
    
        while(uq.size()>0){
            int cur = uq.front();
            uq.pop();
            int size=sides[cur].size();
            for(int i=0;i<size;i++){
                if(dis[cur]+sides[cur][i].second<dis[sides[cur][i].first]){
                    dis[sides[cur][i].first]=dis[cur]+sides[cur][i].second;
                    uq.push(sides[cur][i].first);
                }
            }   
        }
        cout<<dis[e]<<endl; 
    }





    return 0;
}