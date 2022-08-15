#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,e;cin>>n>>e;
        vector<vector<int> > side(n);
        vector<int> degree(n,0);
        for(int i=0;i<e;i++){
            int a,b;cin>>a>>b;
            degree[a]++;
            degree[b]++;
            side[a].push_back(b);
            side[b].push_back(a);
        }
        int fmaxans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        for(int i=0;i<n;i++){
            pq.push({degree[i],i});
            int ans=0;
            for(auto g : side[i]){
                if(g>i) ans++;
            }
            fmaxans = max(ans,fmaxans);
        }

        int smaxans=0;
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            if(temp.first!=degree[temp.second]) continue;
            smaxans = max(smaxans,temp.first);
            degree[temp.second]=-1;
            for(auto i : side[temp.second]){
                if(degree[i]>=0){
                    degree[i]--;
                    pq.push({degree[i],i});
                }
            }
        }
        cout<<fmaxans<<" "<<smaxans<<"\n";







    }
    return 0;
}