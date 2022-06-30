#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> match;
bitset<510> vis;
vector<vector<int> > side;
bool dfs(int r){
	if(r<0) return false;
	for(auto i : side[r]){
		if(!vis[i]){
			vis[i]=1;
			if(match[i]==-1 || dfs(match[i])){
				match[i]=r;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int k;cin>>k;
	side.resize(n);
	match.resize(n);
	fill(match.begin(),match.end(),-1);
	for(int i=0;i<k;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		side[a].push_back(b);
	}
	for(int i=0;i<n;i++){
		vis.reset();
		dfs(i);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(match[i]>=0) ans+=1;
	}
	cout<<ans<<"\n";
	return 0;
}
