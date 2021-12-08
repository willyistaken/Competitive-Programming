#include <bits/stdc++.h>
using namespace std;
int j=0;
void dfs(int now,int parent,vector<int> nodes[],int yes[]){
    yes[now]=(-1)*yes[parent];
    for(auto &i:nodes[now]){
        if(yes[i]==yes[now]){
            j=1;
        }
        if(yes[i]==0){
        dfs(i,now,nodes,yes);}
    }
}
int main(){
    while(true){
    j=0;
    int n,m;cin>>n>>m;
    if(n==0&&m==0) return 0;
    vector<int> nodes[n];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        nodes[a-1].push_back(b-1);
        nodes[b-1].push_back(a-1);
    }
int yes[n]={0};
yes[0]=1;
dfs(0,0, nodes, yes);
if(j==1){
    cout<<"No"<<endl;
}
if(j==0){
    cout<<"Yes"<<endl;
}
    }
}