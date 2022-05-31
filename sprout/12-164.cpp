#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int time[n];
    for(int i=0;i<n;i++) cin>>time[i];
    vector<vector<int> > sides(n);
    vector<vector<int> > rsides(n);
    int in[n]={0};
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        sides[a-1].push_back(b-1);
        in[b-1]+=1;
        rsides[b-1].push_back(a-1);
    }
   vector<int> toposort;
   queue<int> inzero;
   for(int i=0;i<n;i++){
       if(in[i]==0) inzero.push(i);
   } 
    while(!inzero.empty()){
        int temp = inzero.front();
        inzero.pop();
        toposort.push_back(temp);
        for(auto i :sides[temp]){
            in[i]-=1;
            if(in[i]==0){
                inzero.push(i);
            }
        }
    }
    pair<int,int> dp[n]={{0,-1}};
    int maxtime=0;
    for(int i=0;i<n;i++){
        int maxn=0;
        int maxid=-1;
        for(auto j: rsides[toposort[i]] ){
             maxid = (maxn<dp[j].first) ? j:maxid;
             maxn = max(maxn,dp[j].first);
        }
        dp[toposort[i]]={maxn+time[toposort[i]],maxid};
        maxtime=max(maxtime,dp[toposort[i]].first);
    } 
    queue<int> tobeprocess;
    for(int i=0;i<n;i++){
        if(dp[i].first>=maxtime) tobeprocess.push(i);
    }
    set<int> s;
    while(!tobeprocess.empty()){
        int head=tobeprocess.front();
        tobeprocess.pop();
        while(head>=0){
            s.insert(head);
            head=dp[head].second;
        }
    }
    cout<<s.size()<<endl;
    return 0;
}