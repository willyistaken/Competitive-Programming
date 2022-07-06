#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int > > side;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	side.resize(n);
	vector<int > toposort;
	vector<vector<pair<int,int> > > rside(n);
	int ind[n]={0};
	ll dp[n]={0};
	for(int i=0;i<m;i++){
		int a,b,v;cin>>a>>b>>v;
		a--;b--;
		side[a].push_back(b);
		rside[b].push_back({a,v});
		ind[b]+=1;
	}
	toposort.push_back(0);
	for(int i=0;i<toposort.size();i++){
		for(auto j : side[toposort[i]]){
			ind[j]--;
			if(ind[j]==0) toposort.push_back(j);
		}
	}
	ll sum=0;
	for(auto i =1;i<n;i++){
		ll minn = LONG_LONG_MAX;
		for(auto r : rside[toposort[i]]){
			minn = min(minn, dp[r.first]+r.second);
		}
		dp[toposort[i]]=minn;
		sum+=minn;
	}
	cout<<sum<<"\n";
	return 0;
}
