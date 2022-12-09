#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
vector<int> side[N];
vector<int> dps[N];
bool vis[N];
int ord[N];
int t;
void dfs(int v){
	vis[v]=1;
	for(auto i : side[v]){
		if(!vis[i]) dfs(i);
	}
	ord[v]=++t;
}
const int MOD = 1e9+7;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++) arr[i] = i+1;

	while(m--){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		dps[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	sort(arr,arr+n,[&](int a,int b){return ord[a]>ord[b];});
	int dp[n+1] = {0};
	dp[1] = 1;;
	for(auto i : arr){
		for(int d : dps[i]){
			dp[i] = (dp[i]+dp[d])%MOD;
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}

