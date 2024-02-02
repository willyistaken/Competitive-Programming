
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
vector<int> side[N];
ll v[N];
pair<ll,int> dp[N][2];
ll nowc;
void dfs(int cur,int p){
	pair<ll,int> sum = {0,0};
	pair<ll,int> maxn = {-1e18,-1e9};
	pair<ll,int> smaxn = {-1e18,-1e9};
	pair<ll,int> temp = {0,0};
	for(auto i : side[cur]){
		if(i==p) continue;
		dfs(i,cur);
		sum.first+=dp[i][0].first;
		sum.second+=dp[i][0].second;
		temp = {dp[i][1].first-dp[i][0].first,dp[i][1].second-dp[i][0].second};
		if(maxn<=temp){
			smaxn = maxn;
			maxn = temp; 
		}else if(smaxn<=temp){
			smaxn = temp;
		}
	}
	temp = {v[cur]+nowc,1};
	if(maxn<=temp){
			smaxn = maxn;
			maxn = temp; 
	}else if(smaxn<=temp){
			smaxn = temp;
	}
	dp[cur][0] = max(sum,{sum.first+maxn.first+smaxn.first,sum.second+maxn.second+smaxn.second});
	dp[cur][1] = {sum.first+maxn.first,sum.second+maxn.second};
}
int n,k;
void cleandp(){
	for(int i=1;i<=n;i++){
		dp[i][0] = dp[i][1] = {0,0};
	}
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k; 
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	ll L = -5e9; ll R = 5e9; 
	nowc = R;
	dfs(1,0);
	if(dp[1][0].second<2*k){
		cout<<"The God Had Left...\n";
		return 0;
	}
	while(R-L>1){
		ll M = (L+R)/2;
		nowc = M;
		dfs(1,0);
		if(dp[1][0].second>=2*k) R = M;
		else L = M;
	}
	nowc = R;
	dfs(1,0);
	cout<<dp[1][0].first-(2*k*nowc)<<"\n";
	
	
	return 0;
}

