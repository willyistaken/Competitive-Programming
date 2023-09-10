#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


bool works[5005][5005];
vector<int> side[5005];
int sz[5005];
ll maxans[5005];
void dfs(int cur){
	for(auto i : side[cur]){
		dfs(i);
		sz[cur]+=sz[i];
	}
	sz[cur]++;
}

void get(int cur){
	vector<int> g;
	works[cur][0]=1;
	for(auto i : side[cur]){
		get(i);
		for(int v = sz[cur]-1;v>=sz[i];v--){
			works[cur][v]|=works[cur][v-sz[i]];
		}
	}
	for(int v=0;v<=sz[cur]-1;v++){
		if(works[cur][v]) maxans[cur] = max(maxans[cur],1LL*v*(sz[cur]-1-v));
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=2;i<=n;i++){
		int a;cin>>a;
		side[a].push_back(i);
	}
	dfs(1);
	get(1);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans+=maxans[i]	;
	}
	cout<<ans<<"\n";
	return 0;
}
