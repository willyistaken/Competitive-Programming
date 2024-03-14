#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e5+5;
vector<pair<int,int> > side[N];
ll dis[N];
void solve(){
	int k,m;cin>>k>>m;	
	for(int i=0;i<k;i++){
		dis[i]=1e10;
		side[i].clear();
	}

	for(int i=0;i<k;i++){
		int g = (1LL*i*10)%k;
		side[i].push_back({g,0});
		g = (i+1)%k;
		side[i].push_back({g,1});
	}
	deque<int> q;
	dis[1]=1;
	q.push_back(1);
	while(q.size()){
		int cur = q.front();
		q.pop_front();
		for(auto e : side[cur]){
			if(dis[e.first]>dis[cur]+e.second){
				dis[e.first]=dis[cur]+e.second;
				if(e.second){
					q.push_back(e.first);
				}else{
					q.push_front(e.first);
				}
			}
		}
	}
	cout<<dis[m]<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
