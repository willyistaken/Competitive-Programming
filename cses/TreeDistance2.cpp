#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
int sz[N];
ll ans[N];
ll dep[N];
int n;
vector<int> side[N];
int getsz(int v){
	sz[v]=1;	
	for(auto i : side[v]){
		if(!sz[i]) {
			dep[i] = dep[v]+1;
			sz[v]+=getsz(i);
		}
	}
	return sz[v];
}

void dfs(int v){
	for(auto i : side[v]){
		if(!ans[i]){
			ans[i] = ans[v]+(n-2*sz[i]);
			dfs(i);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	getsz(1);
	for(int i=1;i<=n;i++){
		ans[1]+=dep[i];
	}
	dfs(1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}

