#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int MAXN = 10005;
vector<int> side[MAXN];
int vis[MAXN],low[MAXN],t;
stack<int> stk;
vector<vector<int> > bcc;
map<pair<int,int>,int> sidecnt;
void dfs(int r,int from){
	vis[r]=low[r]=++t;	
	stk.push(r);
	for(auto i :side[r]){
		if(i==from && sidecnt[make_pair(min(i,r),max(i,r))]<2) continue;
		if(!vis[i]){
			dfs(i,r);		
		}
		low[r]=min(low[r],low[i]);
	}
	if(low[r]==vis[r]){
		bcc.push_back(vector<int>());
		while(stk.size() && stk.top()!=r){
			bcc[bcc.size()-1].push_back(stk.top());
			stk.pop();
		}
		bcc[bcc.size()-1].push_back(stk.top());
		stk.pop();
		sort(bcc[bcc.size()-1].begin(),bcc[bcc.size()-1].end());
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
		if(a>b) swap(a,b);
		sidecnt[make_pair(a,b)]++;
	}
	dfs(0,0);
	sort(bcc.begin(),bcc.end());
	for(int i=1;i<=bcc.size();i++){
		cout<<i<<":";
		for(auto g : bcc[i-1]){
			cout<<" "<<g;
		}
		cout<<"\n";
	}
	return 0;
}
