#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void dfs(int r,vector<int> side[],stack<int> &toposort,bool vis[]){
	vis[r]=1;
	for(auto i : side[r]){
		if(!vis[i]) dfs(i,side,toposort,vis);
	}
	toposort.push(r);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		int w[n+1];
		bool vis[n+1]={0};
		memset(vis,0,sizeof(vis));
		stack<int> toposort;
		vector<int> side[n+1];
		vector<int> rside[n+1];
		bool hasin[n+1]={0};
		for(int i=1;i<=n;i++){
			cin>>w[i];
			int k;cin>>k;
			for(int g=0;g<k;g++) {
				int a;cin>>a;
				side[i].push_back(a);
				rside[a].push_back(i);
				hasin[a]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(!hasin[i]) dfs(i,side,toposort,vis);
		}
		int ans=0;
		while(toposort.size()){
			int tp = toposort.top();
			int maxn=0;
			for(auto i : rside[tp]){
				maxn = max(maxn,w[i]);	
			}
			w[tp]= maxn+w[tp];
			ans = max(ans,w[tp]);
			toposort.pop();
		}
		cout<<ans<<"\n";	
		
	}


	return 0;
}
