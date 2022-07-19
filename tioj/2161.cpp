#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5+10;
vector<pair<int,int> > side[MAXN];
int depth[MAXN];
int t;

void dfs(int r){
	depth[r]=++t;
	for(auto i : side[r]){
		if(!depth[i]) dfs(i);		
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cout<<(cin>>n>>q);
	for(int i=0;i<n;i++) {
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
			
	


	return 0;
}
