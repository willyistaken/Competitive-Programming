#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1005;
bool vis[N];
int match[N];
int match2[N];
vector<int> side[N];
bool dfs(int v){
    vis[v]=1;
    for(auto i : side[v]){
        if(match[i]==-1 || (!vis[match[i]]&&dfs(match[i]))){
            match[i]=v;
            return 1;
        }
    }
    return 0;
}
vector<int> newside[2*N];
bool vis2[2*N];
void findU(int cur){
    vis2[cur]=1;
    for(auto i : newside[cur]){
        if(!vis2[i]) findU(i);
    }
}
int main(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        side[a].push_back(b);
    }
    for(int i=1;i<=k;i++) match[i]=-1;
    for(int i=1;i<=k;i++){
        fill(vis,vis+k+1,0);
        dfs(i);
    }
    for(int i=1;i<=k;i++) {
        if(match[i]!=-1) match2[match[i]]=i;
    }
    for(int i=1;i<=k;i++){
        for(auto u : side[i]){
            if(u==match2[i]) newside[k+u].push_back(i);
            else newside[i].push_back(k+u);
        }
    }
    for(int i=1;i<=k;i++){
        if(match2[i]==0) findU(i);
    }
    int A = 0;
    int B = 0;
    for(int i=1;i<=k;i++) if(!vis2[i]) A++;
    for(int i=k+1;i<=2*k;i++) if(vis2[i]) B++;
    cout<<A<<" "<<B<<"\n";
    for(int i=1;i<=k;i++) if(!vis2[i]) cout<<i<<" ";
    cout<<"\n";
    for(int i=k+1;i<=2*k;i++) if(vis2[i]) cout<<i-k<<" ";
    cout<<"\n";
}
