#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int MOD = 1e9+7;
struct T{
	ll dis=1e18;
	int cnt=0;
	int minn=1e9;
	int maxn=0;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<pair<int,ll> > side[n];
	while(m--){
		int a,b;cin>>a>>b;
		a--;b--;
		ll c;cin>>c;
		side[a].push_back({b,c});
	}
	T dp[n];
	dp[0].dis = 0;
	dp[0].cnt = 1;
	dp[0].minn = 1;
	dp[0].maxn = 1;
	priority_queue<pair<ll,int> ,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;
	pq.push({0,0});
	while(pq.size()){
		auto t = pq.top();
		pq.pop();
		if(t.first>dp[t.second].dis) continue;
		for(auto i : side[t.second]){
			if(dp[i.first].dis>t.first+i.second){
				dp[i.first].dis = t.first+i.second;
				dp[i.first].cnt = dp[t.second].cnt;
				dp[i.first].minn = dp[t.second].minn+1;
				dp[i.first].maxn = dp[t.second].maxn+1;
				pq.push({dp[i.first].dis,i.first});
			}
			else if(dp[i.first].dis==t.first+i.second){
				//cout<<i.first<<" "<<t.second<<"\n";
				dp[i.first].cnt = (dp[i.first].cnt+dp[t.second].cnt)%MOD;
				dp[i.first].minn = min(dp[i.first].minn,dp[t.second].minn+1);
				dp[i.first].maxn = max(dp[i.first].maxn,dp[t.second].maxn+1);
			}
		}
	}
	cout<<dp[n-1].dis<<" "<<dp[n-1].cnt<<" "<<dp[n-1].minn-1<<" "<<dp[n-1].maxn-1<<"\n";
	return 0;
}
