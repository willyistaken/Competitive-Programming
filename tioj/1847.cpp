#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bitset<100010> vis;
struct pd{
	int p;
	int d;
};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vis.reset();
	int people[n];
	for(int i=0;i<n;i++) cin>>people[i];
	vector<vector<int> >  side(n);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		side[a].push_back(b);
		side[b].push_back(a);
	}
	int D;cin>>D;
	queue<pd> bfs;
	bfs.push({0,0});
	ll ans=people[0];;
	vis[0]=1;
	while(!bfs.empty()){
		pd temp = bfs.front();
		bfs.pop();
		if(temp.d>=D) continue;
		for(auto i : side[temp.p]){
			if(!vis[i]){
				vis[i]=1;
				ans+=people[i];
				bfs.push({i,temp.d+1});
			}
		}
	}

	cout<<ans<<"\n";

	
	return 0;
}
