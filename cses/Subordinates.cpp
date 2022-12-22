#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
vector<int> side[N];
int dp[N];

int ans(int v){
	if(dp[v]) return dp[v];
	if(side[v].size()==0) return 0;
	for(auto i : side[v]){
		dp[v]+=ans(i)+1;
	}
	return dp[v];
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=2;i<=n;i++){
		int a;cin>>a;
		side[a].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cout<<ans(i)<<" ";
	}
	cout<<"\n";
	return 0;
}
