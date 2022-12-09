#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	vector<pair<int,ll> > side[n];
	vector<priority_queue<ll>  > dis(n);
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		side[a].push_back({b,c});
	}
	dis[0].push(0);
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	pq.push({0,0});
	while(pq.size()){
		auto t = pq.top();
		pq.pop();
		if((dis[t.second].size() && dis[t.second].top()<t.first)) continue;
		for(auto i : side[t.second]){
			if(dis[i.first].size()<k || dis[i.first].top()>t.first+i.second){
				dis[i.first].push(t.first+i.second);
				if(dis[i.first].size()>k) dis[i.first].pop();
				pq.push({t.first+i.second,i.first});
			}
		}
	}
	stack<ll> ans;
	while(dis[n-1].size()){
		ans.push(dis[n-1].top());
		dis[n-1].pop();
	}
	while(ans.size()){
		cout<<ans.top()<<" ";
		ans.pop();
	}
	cout<<"\n";
	return 0;
}
