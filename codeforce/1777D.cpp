#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 1e9+7;
const int N = 2e5+5;
int d[N];

vector<int> side[N];

void dfs(int cur){
	d[cur]=1;
	for(auto i : side[cur]){
		if(!d[i]){
			dfs(i);
			d[cur] = max(d[cur],d[i]+1);
		}
	}
}

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) {
		d[i]=0;
		side[i].clear();
	}
	ll r  = 1;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
		r = (r*2)%MOD;
	}
	dfs(1);
	ll sum = 0;
	for(int i=1;i<=n;i++) sum = (sum+d[i])%MOD;
	cout<<(r*sum)%MOD<<"\n";
	return ;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
