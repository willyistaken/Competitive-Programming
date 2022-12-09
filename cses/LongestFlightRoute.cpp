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
	pair<int,int> dp[n+1] = {{0,0}};
	dp[1] = {1,-1};
	bool haso = 0;
	for(auto i : arr){
		if(!haso){
			if(i==1) haso=1;
			continue;
		}
		for(int d : dps[i]){
			dp[i] = max(dp[i],{dp[d].first,d});
		}
		if(dp[i].first==0) continue;
		dp[i].first++;
	}
	if(dp[n].first==0) cout<<"IMPOSSIBLE\n";
	else{
		cout<<dp[n].first<<"\n";
		int cur=  n;
		stack<int> st;
		for(int i=0;i<dp[n].first;i++){
			st.push(cur);
			cur = dp[cur].second;
		}
		while(st.size()){
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<"\n";
	}
	return 0;
}
