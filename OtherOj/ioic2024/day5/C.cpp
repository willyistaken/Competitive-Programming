#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 5e5+5;
const int MOD = 1e9+7;
vector<pair<int,int> > side[N];
vector<pair<int,int> > rside[N];
int in[N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	if(n>1005) return 0;
	for(int i=0;i<m;i++){
		int a,b,w;cin>>a>>b>>w;	
		side[a].push_back({b,w});
		rside[b].push_back({a,w});
		in[b]++;
	}
	vector<int> order;
	queue<int> remove;
	for(int i=1;i<=n;i++){
		if(in[i]==0) remove.push(i);
	}
	while(remove.size()){
		for(auto i : side[remove.front()]){
			in[i.first]--;
			if(in[i.first]==0) remove.push(i.first);
		}
		order.push_back(remove.front());
		remove.pop();
	}
	cout<<"-1\n";
	for(int g=2;g<n;g++){
		vector<pair<ll,ll> > dp(n+1,{-1e18,0});
		dp[1].first = 0;
		dp[1].second = 1;
		for(auto i : order){
			if(i==g) continue;
			for(auto u : rside[i]){
				if(dp[i].first<dp[u.first].first+u.second){
					dp[i].first=dp[u.first].first+u.second;
					dp[i].second = dp[u.first].second;
				}else if(dp[i].first==dp[u.first].first+u.second){
					dp[i].second=(dp[i].second+dp[u.first].second)%MOD;
				}
			}
		}
		if(dp[n].first<0){
			cout<<"-1\n";
		}else{
			cout<<dp[n].first<<" "<<dp[n].second<<"\n";
		}
	}
	cout<<"-1\n";
	return 0;
}
