#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n,m;cin>>n>>m;
    vector<vector<int> > sides(n);
    int in[n]={0};
    priority_queue<int,vector<int>,greater<int> > zeroin;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b; 
        sides[a].push_back(b);
        in[b]+=1;
    }
    for(int i=0;i<n;i++){
        if(in[i]==0){
            zeroin.push(i);
        }
    }
    queue<int> ans;
    while(!zeroin.empty()){
        int cur = zeroin.top();
        zeroin.pop();
        ans.push(cur);
        for(auto i : sides[cur]){
            in[i]-=1;
            if(in[i]==0) zeroin.push(i);
        }

    }

    if(ans.size()<n){
        cout<<"QAQ\n";
    }else{
        while(!ans.empty()){
            cout<<ans.front()<<" \n"[ans.size()==1];
            ans.pop();
        }
    }
    }


    return 0;
}