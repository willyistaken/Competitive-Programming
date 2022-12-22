#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;
const int N = 2e5+5;
vector<int> side[N];
int mxsz[N];
int sz[N];
void dfs(int v){
	sz[v]++;
	for(auto i : side[v]){
		if(!sz[i]){ dfs(i);
		mxsz[v] = max(mxsz[v],sz[i]);
		sz[v]+=sz[i];}
	}
	mxsz[v] = max(mxsz[v],n-sz[v]);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	dfs(1);	
	for(int i=1;i<=n;i++){
		if(mxsz[i]<=(n/2)) {
			cout<<i<<"\n";
			return 0;
		}
	}
	return 0;
}
