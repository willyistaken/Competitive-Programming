#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
 
const int N =5005;
int H[N];
int C[N];
ll sz[N];
vector<int> side[N];
ll dp[N][N];
 
bool vis[N];
ll getsize(int cur){
	sz[cur]	=C[cur];
	for(auto i : side[cur]){
		sz[cur]+=getsize(i);
	}
	return sz[cur];
}
int n;
void get(int cur){
	vis[cur]=1;
	dp[cur][n+1]=1e18;
	for(auto i : side[cur]){
		get(i);
		for(int k=1;k<=n;k++){
			dp[cur][k]+=dp[i][k];
		}
	}
	dp[cur][H[cur]]-=C[cur];
	for(int k=n;k>=1;k--){
		dp[cur][k] = min(dp[cur][k+1],dp[cur][k]);
	}
	return ;
}
 
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;	
	vector<int> d;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a>>H[i]>>C[i];
		d.push_back(H[i]);
		if(a!=i) side[a].push_back(i);
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=1;i<=n;i++){
		H[i] = lower_bound(d.begin(),d.end(),H[i])-d.begin()+1;
	}
 
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		getsize(i);
		get(i);
		ans+=sz[i]+dp[i][1];
	}
	for(int i=1;i<=n;i++){
		dp[i][n+1]=0;
		for(int k=n;k>=1;k--) cout<<dp[i][k]-dp[i][k+1]<<" ";
		cout<<"\n";
	}
	cout<<ans<<"\n";
		
 
	return 0;
}
