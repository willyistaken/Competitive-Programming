#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
vector<int> side[N];
bool vis[N];
pair<int,int> dfs(int v){
	vis[v]=1;
	ll sans=  0;
	ll maxc= 0;
	bool hasc=0;
	for(auto i : side[v]){
		if(!vis[i]){
			hasc=1;
			pair<int,int> t = dfs(i);	
			sans+=max(t.first,t.second);
			maxc = max(-max(t.first,t.second)+t.second+1LL,maxc);	
		}
	}
	if(!hasc) return {0,0};
	else return {sans+maxc,sans};
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	pair<int,int> t = dfs(1);
	cout<<max(t.first,t.second)<<"\n";
	return 0;
}
