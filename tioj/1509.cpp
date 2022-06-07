#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	vector<vector<pair<int,int> > > side(n);
	for(int i=0;i<m;i++){
		int a,b,w;cin>>a>>b>>w;
		a-=1;
		b-=1;
		side[a].push_back({b,w});
		side[b].push_back({a,w});
	}
	vector<ll> dis(n,1e10);
	dis[0]=0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<side[t].size();i++){
			if(dis[side[t][i].first]>dis[t]+side[t][i].second)	{
				dis[side[t][i].first] = dis[t]+side[t][i].second;
				q.push(side[t][i].first);
			}

		}
	}
	ll sum=0;
	for(int i=0;i<n;i++){
		if(dis[i]>5*1e9){
			cout<<0<<endl;
			return 0;
		}
		sum+=dis[i];

	}
	cout<<sum<<endl;
	return 0;



}


