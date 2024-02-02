#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 3e5+5;
 
vector<pair<int,int> > side[N];
int in[N],out[N];
bool vis[N];
int cur[N];
vector<pair<int,int> > ans;
void dfs(int v){
    for(;cur[v]<side[v].size();cur[v]++){
        int i = cur[v];
        int u = side[v][i].first;
        int id = side[v][i].second;
        if(vis[id]) continue;
        vis[id]=1;
        dfs(u);
        ans.push_back({v,u});
    }
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        out[a]++;
        in[b]++;
        side[a].push_back({b,i});
    }
    if(out[1]-in[1]!=1 || out[n]-in[n]!=-1){
        cout<<0<<"\n";
        return 0;
    }
    for(int i=2;i<n;i++){
        if(in[i]!=out[i]){
            cout<<0<<"\n";
            return 0;
        }
    }
    dfs(1);
    if(ans.size()!=m){
        cout<<0<<"\n";
        return 0;
    }
	vector<pair<int,int> > ans2 = ans;
	ans.clear();
	for(int i=1;i<=n;i++){
		reverse(side[i].begin(),side[i].end());
	}
	fill(vis,vis+m+1,0);
	fill(cur,cur+n+1,0);
	dfs(1);
	bool k = 0;
	for(int i=0;i<m;i++) {
		if(ans[i]!=ans2[i]) k=1;
	}
	cout<<1+k<<"\n";
	reverse(ans.begin(),ans.end());
    for(auto i : ans){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}
