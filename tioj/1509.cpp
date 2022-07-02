#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<int,int> > > side;
vector<vector<pair<int,int> > > rside;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	side.resize(n);rside.resize(n);
	for(int i=0;i<m;i++){
		int a,b,r;cin>>a>>b>>r;
		a--;b--;
		side[a].push_back({b,r});
		rside[b].push_back({a,r});
	}
	ll disto[n];
	ll disback[n];
	fill(disto,disto+n,1e15);
	fill(disback,disback+n,1e15);
	disto[0]=disback[0]=0;
	queue<int> tbp;//to be process
	tbp.push(0);
	while(!tbp.empty()){
		for(auto p:side[tbp.front()]){
			if(disto[tbp.front()]+p.second<disto[p.first]){
				disto[p.first] =	disto[tbp.front()]+p.second;
				tbp.push(p.first);
			}
		}
		tbp.pop();
	}
	tbp.push(0);
	while(!tbp.empty()){
		for(auto p:rside[tbp.front()]){
			if(disback[tbp.front()]+p.second<disback[p.first]){
				disback[p.first] =	disback[tbp.front()]+p.second;
				tbp.push(p.first);
			}
		}
		tbp.pop();
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if(disto[i]>5e14 || disback[i]>5e14){
			cout<<0<<"\n";
			return 0;
		}else{
			ans+=disto[i]+disback[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
