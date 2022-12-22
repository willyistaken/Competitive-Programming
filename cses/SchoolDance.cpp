#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int n,m;
vector<vector<int>> nside;
vector<int> match;
vector<bool> vis;

bool dfs(int v){
	for(auto i : nside[v]){
		if(vis[i]) continue;
		vis[i]=1;
		if(!match[i] || dfs(match[i])){
			match[i] = v;
			return 1;
		}
	}
	return 0;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;	
	int k;cin>>k;
	nside.resize(n+1);
	match.resize(m+1,0);
	vis.resize(m+1,0);
	while(k--){
		int a,b;cin>>a>>b;		
		nside[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		fill(vis.begin(),vis.end(),0);	
		dfs(i);
	}
	vector<pair<int,int>> arr;	
	for(int i=1;i<=m;i++){
		if(match[i]) arr.push_back({match[i],i});
	}
	cout<<arr.size()<<"\n";
	for(auto i : arr){
		cout<<i.first<<" "<<i.second<<"\n";
	}
	return 0;
}
