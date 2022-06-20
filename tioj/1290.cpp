#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m){
    int st,et;cin>>st>>et;
    vector<vector<pair<int,int> > > sides(n+1);
    for(int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        sides[a].push_back({b,w});
        sides[b].push_back({a,w});
    } 
    
    vector<ll> dis(n+1,1e11);
    dis[st]=0;
    queue<int> upd;
    upd.push(st);
    while(!upd.empty()){
        int temp = upd.front();
        upd.pop();
        for(auto i : sides[temp]){
            if(dis[i.first]>dis[temp]+i.second){
                dis[i.first] = dis[temp]+i.second;
                upd.push(i.first);
            }
        }
    }
    if(dis[et]<1e11){
    cout<<dis[et]<<endl;
    }else{
        cout<<"He is very hot\n";
    }
    }




    return 0;
}