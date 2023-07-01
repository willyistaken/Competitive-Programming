#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll
const int N = 1e5+5;
vector<pair<int,int> > side[N];
int cntchild[N];
int dis[N];
int dissum[N];

void dfs(int cur){
	for(auto i : side[cur]){
		dis[i.first] = dis[cur]+i.second;
		dfs(i.first);
		cntchild[cur]+=cntchild[i.first];
		dissum[cur]+=dissum[i.first];
	}
	dissum[cur]+=dis[cur];
	cntchild[cur]++;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,c;cin>>n>>c;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		int w;cin>>w;
		side[b].push_back({a,w});
	}
	dfs(1);
	ll allsum = dissum[1];
	ll minn = allsum;
	for(int i=2;i<=n;i++){
		minn = min(minn,allsum-(cntchild[i]*(dis[i]-c)));	
	}
	cout<<minn<<"\n";
	return 0;
}
