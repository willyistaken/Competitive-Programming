#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 300005;
vector<int> side[MAXN];
int vis[MAXN],low[MAXN],t;
int sccnow;
stack<int> stk;bitset<MAXN> instack;
int scc[MAXN];
void dfs(int r){
	vis[r]=low[r]=++t;
	stk.push(r);instack[r]=1;
	for(auto i : side[r]){
		if(!vis[i]){
			dfs(i);
		}
		if(instack[i]) low[r] = min(low[r],low[i]);
	}
	if(low[r]==vis[r]){
		sccnow++;
		while(stk.top()!=r){
			scc[stk.top()]=sccnow;
			instack[stk.top()]=0;
			stk.pop();
		}
		scc[r]=sccnow;
		instack[r]=0;
		stk.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	instack.reset();
	int prev=1e8;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		if(a>=prev) side[i].push_back(i-1);
		if(prev>=a) side[i-1].push_back(i);
		prev= a;
	}
	for(int i=1;i<=n;i++) side[0].push_back(i);//make 0 the point which can go to every node
	string s;cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='T') side[i+1].push_back(0);
	}
	for(int i=0;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	vector<int> sccside[sccnow+1]; 	
	int w[sccnow+1]={0};
	for(int i=0;i<=n;i++){
		if(i) w[scc[i]]+=1;
		for(auto j : side[i]){
			if(scc[j]!=scc[i]){
				sccside[scc[i]].push_back(scc[j]);
			}
		}
	}
	int g = scc[k];
	for(int i=1;i<=g;i++){
		int maxn = 0; 
		for(auto p : sccside[i]){
			maxn = max(maxn,w[p]);	
		}
		w[i] = w[i]+maxn;
	}
	cout<<w[g]<<"\n";


	return 0;
}
